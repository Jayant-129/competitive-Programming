#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<string>> dp_min, dp_max;
ll m, s;

string dpsolve_min(ll i, ll s){
    if(i == m && s == 0) return "";
    if(i == m || s < 0) return "-1";
    if(dp_min[i][s] != "#") return dp_min[i][s];

    string ans = "-1";
    for(int d = 0; d < 10; d++){
        if(i == 0 && d == 0 && m != 1) continue;
        if(d > s) continue;

        string res = dpsolve_min(i + 1, s - d);
        if(res != "-1") {
            res = char('0' + d) + res;
            if(ans == "-1" || res < ans) {
                ans = res;
            }
        }
    }
    dp_min[i][s] = ans;
    return ans;
}

string dpsolve_max(ll i, ll s){
    if(i == m && s == 0) return "";
    if(i == m || s < 0) return "-1";
    if(dp_max[i][s] != "#") return dp_max[i][s];

    string ans = "-1";
    for(int d = 9; d >= 0; d--){
        if(i == 0 && d == 0 && m != 1) continue;
        if(d > s) continue;

        string res = dpsolve_max(i + 1, s - d);
        if(res != "-1") {
            res = char('0' + d) + res;
            if(ans == "-1" || res > ans) {
                ans = res;
            }
        }
    }
    dp_max[i][s] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> s;
    if(s == 0){
        if(m == 1){
            cout << "0 0\n";
        } else {
            cout << "-1 -1\n";
        }
        return 0;
    }
    dp_min.resize(m + 1, vector<string>(s + 1, "#"));
    dp_max.resize(m + 1, vector<string>(s + 1, "#"));

    string ans_min = dpsolve_min(0, s);
    string ans_max = dpsolve_max(0, s);
    if(ans_min == "-1" || ans_max == "-1"){
        cout << "-1 -1\n";
    } else {
        cout << ans_min << " " << ans_max << "\n";
    }
}
