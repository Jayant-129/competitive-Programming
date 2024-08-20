#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin >> n;
    if(n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    vector<int> v(n,-1);
    int i = 2;
    int j = 1;
    int s = 0;
    int e = n - 1;
    while(s < e){
        v[s] = i;
        i += 2;
        v[e] = j;
        j += 2;
        s++;
        e--;
    }
    v[s] = n;
    for(auto& i: v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}