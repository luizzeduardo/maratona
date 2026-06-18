#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

// Segment tree with lazy range multiply by -1 and point set to -INF
struct SegTree {
    int n;
    vector<ll> mx, mn;
    vector<int> lazy;

    SegTree(int _n, const vector<ll>& init) : n(_n) {
        mx.resize(4 * n + 5);
        mn.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
        build(1, 1, n, init);
    }

    void build(int node, int l, int r, const vector<ll>& init) {
        if (l == r) {
            mx[node] = mn[node] = init[l];
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, init);
        build(node * 2 + 1, mid + 1, r, init);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
    }

    void apply(int node) {
        lazy[node] ^= 1;
        tie(mx[node], mn[node]) = make_pair(-mn[node], -mx[node]);
    }

    void push(int node) {
        if (lazy[node]) {
            apply(node * 2);
            apply(node * 2 + 1);
            lazy[node] = 0;
        }
    }

    void update_range(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node);
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (ql <= mid) update_range(node * 2, l, mid, ql, qr);
        if (qr > mid) update_range(node * 2 + 1, mid + 1, r, ql, qr);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
    }

    void point_set_inf(int node, int l, int r, int idx) {
        if (l == r) {
            mx[node] = mn[node] = -INF;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if (idx <= mid) point_set_inf(node * 2, l, mid, idx);
        else point_set_inf(node * 2 + 1, mid + 1, r, idx);
        mx[node] = max(mx[node * 2], mx[node * 2 + 1]);
        mn[node] = min(mn[node * 2], mn[node * 2 + 1]);
    }

    int query_first_positive(int node, int l, int r) {
        if (mx[node] <= 0) return -1;
        if (l == r) return l;
        push(node);
        int mid = (l + r) / 2;
        if (mx[node * 2] > 0) return query_first_positive(node * 2, l, mid);
        else return query_first_positive(node * 2 + 1, mid + 1, r);
    }

    void flip_prefix(int i) {
        if (i >= 1) update_range(1, 1, n, 1, i);
    }

    void remove(int i) {
        point_set_inf(1, 1, n, i);
    }

    int get_next() {
        return query_first_positive(1, 1, n);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // DP: dp0[s] for t=0, dp1[s] for t=1 (s=1 only)
    vector<ll> dp0(2, -INF), dp1(2, -INF);
    dp0[0] = 0;  // t_{n+1}=0, seen=0

    // back pointers: back[i][state] = previous state info
    // state: 0 -> (0,0), 1 -> (0,1), 2 -> (1,1)
    vector<vector<int>> back(n + 2, vector<int>(3, -1));

    for (int i = n; i >= 1; i--) {
        vector<ll> ndp0(2, -INF), ndp1(2, -INF);
        vector<ll> best(2, -INF);
        best[0] = max(dp0[0], dp1[0]);
        best[1] = max(dp0[1], dp1[1]);

        // t = 0
        for (int s = 0; s <= 1; s++) {
            if (best[s] == -INF) continue;
            ll val = a[i] + best[s];
            if (val > ndp0[s]) {
                ndp0[s] = val;
                // store which t_next gave best[s]
                int t_next = (dp0[s] >= dp1[s]) ? 0 : 1;
                int s_next = s;
                int prev_state = (t_next == 0) ? (s_next == 0 ? 0 : 1) : 2;
                back[i][ (0 == 0) ? (s == 0 ? 0 : 1) : 2 ] = prev_state;
                // actually we need to store for state (0,s)
                int cur_state = (s == 0) ? 0 : 1;
                back[i][cur_state] = prev_state;
            }
        }

        // t = 1 (s = 1 always)
        for (int s_next = 0; s_next <= 1; s_next++) {
            if (best[s_next] == -INF) continue;
            if (s_next == 0 && a[i] <= 0) continue;
            ll val = -a[i] + best[s_next];
            if (val > ndp1[1]) {
                ndp1[1] = val;
                int t_next = (dp0[s_next] >= dp1[s_next]) ? 0 : 1;
                int prev_state = (t_next == 0) ? (s_next == 0 ? 0 : 1) : 2;
                back[i][2] = prev_state;
            }
        }

        dp0 = ndp0;
        dp1 = ndp1;
    }

    // Find best final state
    ll ans = -INF;
    int best_t = -1, best_s = -1;
    if (dp0[0] > ans) { ans = dp0[0]; best_t = 0; best_s = 0; }
    if (dp0[1] > ans) { ans = dp0[1]; best_t = 0; best_s = 1; }
    if (dp1[1] > ans) { ans = dp1[1]; best_t = 1; best_s = 1; }

    // Reconstruct t
    vector<int> t(n + 2, 0); // 1..n+1, t[n+1]=0
    int cur_t = best_t, cur_s = best_s;
    int cur_state = (cur_t == 0) ? (cur_s == 0 ? 0 : 1) : 2;
    for (int i = 1; i <= n; i++) {
        t[i] = cur_t;
        int prev_state = back[i][cur_state];
        if (prev_state == -1) break; // should not happen
        // decode prev_state
        int prev_t, prev_s;
        if (prev_state == 0) { prev_t = 0; prev_s = 0; }
        else if (prev_state == 1) { prev_t = 0; prev_s = 1; }
        else { prev_t = 1; prev_s = 1; }
        cur_t = prev_t;
        cur_s = prev_s;
        cur_state = prev_state;
    }
    t[n + 1] = 0;

    // Determine set S
    vector<int> S;
    for (int i = 1; i <= n; i++) {
        if (t[i] != t[i + 1]) S.push_back(i);
    }

    // Build segment tree to find order
    vector<ll> init(n + 1, -INF);
    for (int i : S) init[i] = a[i];

    SegTree seg(n, init);
    vector<int> ops;
    while (true) {
        int i = seg.get_next();
        if (i == -1) break;
        ops.push_back(i);
        seg.remove(i);
        seg.flip_prefix(i);
    }

    // Output
    cout << ops.size() << "\n";
    for (size_t j = 0; j < ops.size(); j++) {
        if (j) cout << " ";
        cout << ops[j];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}