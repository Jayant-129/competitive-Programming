#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v;
void solve(){
    ll n; cin >> n; 
    v.resize(n,0);
    int cnt = 0;
    int idx = 0;
    for(int i = 0; i < 32; i++){
        if(n & (1 << i)){
            cnt++;
            idx = i;
        }
    }
    if(n <= 4){
        if(n % 2){
            cout <<  n - 1 << endl;
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
        }
        else if(n == 2){
            cout << 2 << endl << 1 << " " <<  2 << endl;
        }
        else{
            cout << 6 << endl << 1 << " " << 3 << " " << 2 << " " << 4 << endl;
        }

    }
    else if(cnt == 1){
        cout << pow(2,idx + 1) - 1 << endl;
        for(int i = 2; i <= n - 3; i++){
            if(i == 3)continue;
            cout << i << " ";
        }
        cout << 1 << " " << 3 << " " << n - 2 << " " << n - 1 << " " << n << endl;
    }
    else if(n % 2){
        cout << n << endl;
        for(int i = 2; i <= (n - 2); i++){
            if(i == 3)continue;
            cout << i << " ";
        }
        cout << 1 << " " << 3  << " " << n -1 << " " << n << endl;
    }
    else{
        ll x = pow(2,idx);
        cout << pow(2,idx + 1) - 1 << endl;
        for(int i = 1; i <= n; i++){
            if(i == x || i == (x - 1) || i == (x + 1)){
                continue;
            }
            cout << i << " ";
        }
        cout << x + 1 << " " << x << " " << x - 1 << endl;
    }

}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}