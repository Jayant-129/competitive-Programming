#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin >> n; 
    if(n % 2 == 0){
        for(int i = 1; i <= (n/2); i++){
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
    else{
        if( n >= 27){
            cout << 1 << " ";
            for(int i = 2; i < 6; i++){
                cout << i << " " << i << " " ;
            }
            cout << 1 << " " << 13 << " ";
            for(int i = 6; i < 13; i++){
                cout << i << " " << i << " " ;
            }
            cout << 1 << " " << 13 << " ";
            ll j = 13;
            for(int i = 28; i <= n; i++){
                if(i % 2 == 0){
                    j++;
                }
                cout << j << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}