#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    if(n == 2 || n == 3 || n == 4){
        cout << -1 << endl;
        return;
    }
    if(n % 2){
        for(int i = 1; i <= n; i += 2){
            if(i == 5){
                continue;
            }
            else{
                cout << i  << " ";
            }
        }
        cout <<  5 << " " << 4 << " ";
        for(int i = 2; i <= n; i += 2){
            if(i == 4){
                continue;
            }
            else{
                cout << i  << " ";
            }
        }
    }
    else{
        for(int i = 1; i <= n; i += 2){
            if(i == 5){
                continue;
            }
            else{
                cout << i  << " ";
            }
        }
        cout <<  5 << " " << 4 << " ";
        for(int i = 2; i <= n; i += 2){
            if(i == 4){
                continue;
            }
            else{
                cout << i  << " ";
            }
        }
    }
    cout << endl;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}