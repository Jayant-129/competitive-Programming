#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    
    // Check condition on self-pairs.
    int selfCount = 0, selfIndex = -1;
    for (int i = 0; i < n; i++){
        if(a[i] == b[i]){
            selfCount++;
            selfIndex = i;
        }
    }
    if(n % 2 == 1){
        if(selfCount != 1){
            cout << -1 << "\n";
            return;
        }
    } else {
        if(selfCount > 0){
            cout << -1 << "\n";
            return;
        }
    }
    
    // For non-self indices check complementary existence:
    // For each i with a[i]!=b[i], there must be some j such that (a[j], b[j]) = (b[i], a[i]).
    // We can count frequencies of ordered pairs.
    unordered_map<ll, int> freq;
    // We'll encode a pair (x, y) as: key = x*(n+1) + y.
    for(int i = 0; i < n; i++){
        if(a[i]==b[i]) continue;
        ll key = a[i]*(n+1LL) + b[i];
        freq[key]++;
    }
    for(int i = 0; i < n; i++){
        if(a[i]==b[i]) continue;
        ll key = a[i]*(n+1LL) + b[i];
        ll compKey = b[i]*(n+1LL) + a[i];
        if(freq[compKey] != freq[key]){
            cout << -1 << "\n";
            return;
        }
    }
    
    // Build a mapping from element value to its index in array a.
    // Since a is a permutation, this mapping is unique.
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++){
        pos[a[i]] = i;
    }
    
    vector<pair<int,int>> ans;
    
    // If n is odd, move the unique self pair to the center
    if(n % 2 == 1){
        int center = n/2;  // 0-indexed center
        if(selfIndex != center){
            // Swap elements at selfIndex and center in both a and b.
            swap(a[selfIndex], a[center]);
            swap(b[selfIndex], b[center]);
            // Update positions in pos mapping: update for the swapped values.
            pos[a[selfIndex]] = selfIndex;
            pos[a[center]] = center;
            ans.push_back({selfIndex, center});
        }
    }
    
    // Process indices 0 to floor(n/2)-1.
    // For i in left half, we want to force: a[i] should equal b[n-1-i] (i.e. b at mirror position)
    // by swapping the element in a that equals b[i] to position n-1-i.
    for (int i = 0; i < n/2; i++){
        int right = n - 1 - i;
        // Find j, the index in a where element equals b[i].
        int j = pos[b[i]];
        // Swap the element at j with the element at right if needed.
        if(j != right){
            swap(a[j], a[right]);
            swap(b[j], b[right]);
            // Update pos mapping for the swapped elements.
            pos[a[j]] = j;
            pos[a[right]] = right;
            ans.push_back({j, right});
        }
    }
    
    // Final verification: for all i, a[i] should equal b[n-1-i]
    for (int i = 0; i < n; i++){
        if(a[i] != b[n - 1 - i]){
            cout << -1 << "\n";
            return;
        }
    }
    
    // Output the swaps.
    cout << ans.size() << "\n";
    for(auto &p: ans){
        // Output in 1-indexed format.
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}