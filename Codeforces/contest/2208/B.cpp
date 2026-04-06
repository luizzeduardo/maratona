#include <bits/stdc++.h>
using namespace std;

def solve():
    t = int(input())
    for _ in range(t):
        n, k, p, m = map(int, input().split())
        costs = list(map(int, input().split()))
        p -= 1  # 0-based index
        
        deck = deque(range(n))
        win_idx = p  # index of win-condition in deck
        energy = 0
        plays = 0
        
        while True:
            # Find actual card indices in first k
            first_k = [deck[i] for i in range(k)]
            
            # Check if win-condition is in first k
            win_pos_in_deck = None
            for i in range(k):
                if deck[i] == p:
                    win_pos_in_deck = i
                    break
            
            if win_pos_in_deck is not None:
                # Play win-condition
                card_idx = win_pos_in_deck
                cost = costs[p]
                if energy + cost > m:
                    break
                energy += cost
                plays += 1
                # Remove from position, append to end
                card = deck[card_idx]
                del deck[card_idx]
                deck.append(card)
            else:
                # Play cheapest in first k
                # Find cheapest card in first k
                min_cost = float('inf')
                min_pos = -1
                for i in range(k):
                    card_id = deck[i]
                    if costs[card_id] < min_cost:
                        min_cost = costs[card_id]
                        min_pos = i
                if energy + min_cost > m:
                    break
                energy += min_cost
                card = deck[min_pos]
                del deck[min_pos]
                deck.append(card)
        
        print(plays)

if __name__ == "__main__":
    solve()