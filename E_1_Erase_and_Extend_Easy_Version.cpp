#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k; cin >> n >> k;
    string s; cin >> s;
    string ans = "{";
    for(int i = 0; i < n; i++){
        string curr = s.substr(0,i + 1);
        while(curr.size() < k){
            curr = curr + curr;
        }
        ans = min(ans,curr.substr(0,k));
    }
    cout << ans << endl;
}

int main(){
  ll t = 1;
  while(t--){
    solve();
  }
}