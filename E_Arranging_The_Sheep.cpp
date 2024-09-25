#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n; vector<char> v;
    bool flag = true;
    for(int i = 0; i < n; i++){
        char x; cin >> x;
        if(flag && x == '.'){
            continue;
        }
        else{
            flag = false;
            v.push_back(x);
        }
    }
    ll cnt = 1;n =  v.size(); ll dist = 0;
    for(int i = 1; i < n; i++){
        if(v[i] == '*'){
            dist += (i - cnt);
            cnt++;
        }
    }
    ll left = 0, right = cnt;
    for(int i = 0; i < n; i++){
        if(v[i] == '*'){
            left++;
            right--;
        }
        else{
            dist = min(dist,dist + left - right);
        }
    }
    cout << dist << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}