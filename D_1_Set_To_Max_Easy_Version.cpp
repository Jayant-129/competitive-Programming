#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            flag = false;
        }
        else if(a[i] == b[i]){
            continue;
        }
        else{
            bool flag1 = false;
            for(int j = i - 1; j >= 0; j--){
                if(b[i] < a[j] || b[i] > b[j]){
                    break;
                }
                if(b[i] == a[j]){
                    flag1 = true;
                    break;
                }
            }
            bool flag2 = false;
            for(int j = i + 1; j < n; j++){
                if(b[i] < a[j] || b[i] > b[j]){
                    break;
                }
                if(b[i] == a[j]){
                    flag2 = true;
                    break;
                }
            }
            if(!flag1 && !flag2){
                flag = false;
            }
        }
    }
    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}