#include<bits/stdc++.h>
using namespace std;
#define ll long long

int query(string s,bool flag){
    ll ans;
    if(flag){
        cout << "!" << " " << s << endl;
        return 0;
    }
    cout << "?" << " " << s << endl;
    cin >> ans;
    cout.flush();
    return ans;
}

void solve(){
    ll n; cin >> n;
    if(n == 0){
        query("",true);
        return;
    }
    string ans = "";
    if(query(ans + '0',false)){
        ans = ans + '0';
    }
    else{
        ans = ans + '1';
    }
    ll cnt = 1;
    while(ans.length() <= n){
        if(ans.length() == n){
            query(ans,true);
            return;
        }
        bool flag2 = true;
        bool flag1 = query('1' + ans,false);
        if(flag1){
            ans = '1' + ans;
            flag2 = false;
        }
        if(flag2){
            flag2 = query('0' + ans,false);
            if(flag2){
                ans = '0' + ans;
            }
        }
        if(!flag1 & !flag2){
            break;
        }
    }
    while(ans.length() <= n){
        if(ans.length() == n){
            query(ans,true);
            return;
        }
        bool flag2 = true;
        bool flag1 = query(ans + '1',false);
        if(flag1){
            ans =  ans + '1';
            flag2 = false;
        }
        if(flag2){
            flag2 = query(ans + '0',false);
            if(flag2){
                ans = ans + '0';
            }
        }
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}