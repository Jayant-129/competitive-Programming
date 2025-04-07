#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; 
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    
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
    
    unordered_map<ll, int> freq;
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

    vector<int> pos(n+1);
    for (int i = 0; i < n; i++){
        pos[a[i]] = i;
    }
    
    vector<pair<int,int>> ans;
    
    if(n % 2 == 1){
        int center = n/2;
        if(selfIndex != center){
            swap(a[selfIndex], a[center]);
            swap(b[selfIndex], b[center]);
            pos[a[selfIndex]] = selfIndex;
            pos[a[center]] = center;
            ans.push_back({selfIndex, center});
        }
    }
  
    for (int i = 0; i < n/2; i++){
        int right = n - 1 - i;

        int j = pos[b[i]];
        if(j != right){
            swap(a[j], a[right]);
            swap(b[j], b[right]);
            pos[a[j]] = j;
            pos[a[right]] = right;
            ans.push_back({j, right});
        }
    }
    
    for (int i = 0; i < n; i++){
        if(a[i] != b[n - 1 - i]){
            cout << -1 << "\n";
            return;
        }
    }
    
    cout << ans.size() << "\n";
    for(auto &p: ans){
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