#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005];
int main(){
    ll n,k;cin>>n>>k;vector<int> v(n);for(int i = 0; i < n; i++) cin >> v[i];
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        dp[i] = 0;
        for(int& x: v){
            //cout << x << endl;
            if(i >= x && dp[i - x] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[k] == 1){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
}