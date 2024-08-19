#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    if( n == 2){
        cout << "ab" << endl;
        return;
    }
    ll idx = 1;
    for(int i = 1; i <= n; i++){
        if(n % i != 0){
            idx = i;
            break;
        }
    }
    string str = "";
    char curr = 'a';
    for(int i = 0; i < idx; i++){
        str = str + (char)(curr + i);
    }
    ll num = n / idx;
    ll mod = n % idx;
    string ans = "";
    for(int i = 0; i < num; i++){
        ans += str;
    }
    for(int i = 0; i < mod; i++){
        ans = ans + str[i];
    }
    cout << ans << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}