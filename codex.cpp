#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll D, S; 

vector<vector<string>> dp;

string better(const string &a, const string &b) {
    if(a == "#") return b;
    if(b == "#") return a;
    if(a.size() != b.size())
         return (a.size() < b.size() ? a : b);
    return (a < b ? a : b);
}

string dpsolve(ll rem, ll mod) {
    if(rem == 0) {
        if(mod == 0)
            return "";  
        else if(mod * 10 % D == 0)
            return "0";
        else if(mod * 100 % D == 0)
            return "00";
        else
            return "#";
    }
    
    if(dp[rem][mod] != "$")
        return dp[rem][mod];
    
    string ans = "#";

    for(int digit = 1; digit <= 9; digit++){
        if(digit > rem) break; // digit cannot exceed remaining sum.
        string sub = dpsolve(rem - digit, (mod * 10 + digit) % D);
        if(sub == "#") continue;
        string candidate = to_string(digit) + sub;
        ans = better(ans, candidate);
    }
    
    dp[rem][mod] = ans;
    return ans;
}

void solve(){
    cin >> D >> S;
    
    // Special-case: if S==0 then the only candidate is "0".
    // (Here we accept 0 only if it is divisible by D.)
    if(S == 0) {
        if(0 % D == 0)
            cout << "0" << "\n";
        else
            cout << -1 << "\n";
        return;
    }
    
    // Initialize dp: dimensions = (S+1) x (D)
    dp.assign(S + 1, vector<string>(D, "$"));
    
    string res = dpsolve(S, 0);
    if(res == "#")
        cout << -1 << "\n";
    else
        cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}