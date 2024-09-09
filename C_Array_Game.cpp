#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll  mini = LLONG_MAX;
    sort(v.begin(),v.end());
    for(auto& i: v){
        mini = min(mini,i);
    }
    if(k >= 3){
        cout << 0 << endl;
        return;
    }
    else if(k == 2){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ll val = abs(v[i] - v[j]);
                mini = min(mini,val);
                auto it = upper_bound(v.begin(),v.end(),val);
                mini = min(abs(val - *it), mini);
                if(it != v.begin()){
                    it--;
                    mini = min(abs(val-*it),mini);
                }
            }
        }
    }
    else{
       for(int i = 0; i < (n-1); i++){
          mini = min(mini ,abs(v[i] - v[i + 1]));
       }
    }
    cout << mini << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    solve();
  }
}