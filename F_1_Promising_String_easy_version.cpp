#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    s = '#' + s;
    vector<pair<int,pair<int,int>>> pre(n + 1);
    pre[0] = {0,{0,0}};
    for(int i = 1; i <= n; i++){
        if(s[i] == '-' && s[i - 1] == '-'){
            pre[i] = pre[i - 2];
            pre[i].second.second++;
        }
        else if(s[i] == '+'){
            pre[i] = pre[i - 1];
            pre[i].second.first++;
        }
        else{
            pre[i] = pre[i - 1];
            pre[i].first++;
        }
    }
    // for(int i = 0; i <= n; i++){
    //     cout << pre[i].first << " " << pre[i].second.first << " " << pre[i].second.second << endl;
    // }
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        ll neg1 = pre[i - 1].first, pos1 = pre[i - 1].second.first, ops1 = pre[i - 1].second.second;
        for(int j = i + 1; j <= n; j++){
            ll neg2 = pre[j].first, pos2 = pre[j].second.first, ops2 = pre[j].second.second;
            ll neg  = neg2 - neg1;
            ll pos = pos2 - pos1;
            ll ops = ops2 - ops1;
            ll diff = abs(pos - neg);
            if(pos < neg){
                ops -= (diff);
                if(ops >= 0 && (ops % 3 == 0)){
                    cnt++;
                    //cout << i << " " << j << endl;
                }
            }
            else if(neg < pos){
                if(diff % 2){
                    ops -= (diff/2);
                    ops -= 2;
                    if(ops >= 0 && (ops % 3 == 0)){
                        cnt++;
                        //cout << i << " " << j << endl;
                    }
                }
                else{
                    ops -= (diff/2);
                    if(ops >= 0 && (ops % 3 == 0)){
                        cnt++;
                        //cout << i << " " << j << endl;
                    }
                }
            }
            else{
                if(ops >= 0 && (ops % 3 == 0)){
                    cnt++;
                    //cout << i << " " << j << endl;
                }
            }
        }
    }
    cout << cnt << endl;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  ll t; cin >> t;
  while(t--){
    solve();
  }
}