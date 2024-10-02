#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,x; cin >> n;
    unordered_map<ll,ll> ump;
    ump.reserve(1024);
    ump.max_load_factor(0.25);
    for(ll i = 0; i < n; i++){
        cin >> x;
        ump[x]++;
    }
    priority_queue<ll> pq;
    for(auto& i: ump){
        pq.push(i.second);
    }
    while(true){
        if(pq.size() == 1 || pq.empty()){
            break;
        }
        auto curr = pq.top(); pq.pop();curr--;
        auto curr2 = pq.top(); pq.pop();curr2--;
        if(curr > 0) pq.push(curr);
        if(curr2 > 0) pq.push(curr2);
    }
    if(pq.empty()){
        cout << 0 << endl;
    }
    else{
        cout << pq.top() << endl;
    }
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}