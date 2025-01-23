#include<bits/stdc++.h>
using namespace std;
#define ll long long
string ans = "";
void solve(){
    string s; cin >> s;
    ll pos = -1; cin >> pos;
    ll n = s.size();
    vector<bool> vis(n,false);
    vector<ll> seq;
    stack<ll> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && s[st.top()] > s[i]){
            seq.push_back(st.top());
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        seq.push_back(st.top());
        st.pop();
    }
    ll curr = s.size();
    ll k = 0;
    while(pos > curr){
        pos -= curr;
        curr--;
        vis[seq[k]] = true;
        k++;
    }
    k = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            k++;
            if(pos == k){
                ans += s[i];
                break;
            }
        }
    }
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
  cout << ans << endl;
}