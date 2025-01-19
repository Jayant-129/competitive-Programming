#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        
        // Structure to hold cow information
        struct Cow {
            int id; // 1-based indexing
            vector<long long> cards;
        };
        
        vector<Cow> cows(n);
        for(int i = 0; i < n; i++){
            cows[i].id = i + 1;
            cows[i].cards.resize(m);
            for(int j = 0; j < m; j++){
                cin >> cows[i].cards[j];
            }
            sort(cows[i].cards.begin(), cows[i].cards.end());
        }
        
        // Sort cows based on their first card in ascending order
        sort(cows.begin(), cows.end(), [&](const Cow &a, const Cow &b) -> bool{
            return a.cards[0] < b.cards[0];
        });
        
        // Extract the permutation p
        vector<int> p;
        for(auto &cow : cows){
            p.push_back(cow.id);
        }
        
        // Simulation to verify if the permutation p is valid
        // Create a mapping from cow id to its sorted cards
        unordered_map<int, vector<long long>> cow_cards_map;
        for(auto &cow : cows){
            cow_cards_map[cow.id] = cow.cards;
        }
        
        // Initialize pointers for each cow to track the next card to place
        unordered_map<int, int> cow_ptr;
        for(auto &cow : cows){
            cow_ptr[cow.id] = 0;
        }
        
        bool valid = true;
        long long pile = -1;
        
        // Total number of rounds is m
        for(int round = 0; round < m && valid; round++){
            // Iterate through cows in permutation p order
            for(auto &cid : p){
                // Check if the cow has a card left to play
                if(cow_ptr[cid] >= m){
                    valid = false;
                    break;
                }
                
                long long current_card = cow_cards_map[cid][cow_ptr[cid]];
                
                // The current card must be greater than the pile's top
                if(current_card > pile){
                    pile = current_card;
                    cow_ptr[cid]++;
                }
                else{
                    // Cannot place the card, invalid permutation
                    valid = false;
                    break;
                }
            }
        }
        
        // After m rounds, all cows should have placed all m cards
        if(valid){
            // Output the permutation p
            for(int i = 0; i < p.size(); i++){
                cout << p[i];
                if(i != p.size() -1){
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        else{
            cout << "-1\n";
        }
    }
}