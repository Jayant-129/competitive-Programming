#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<char>> v;
vector<vector<bool>> vis;
vector<vector<int>> dp;

vector<pair<int, int>> dir = { {-1,0}, {1,0}, {0,-1}, {0,1} };


bool isValid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(int i, int j, int n, int m){
    if(!isValid(i, j, n, m)){
        return false;
    }
    if(vis[i][j]){
        if(dp[i][j] == -1){
            return true;
        }
        else{
            return dp[i][j];
        }
    }
    vis[i][j] = true;
    bool ans = false;

    if(v[i][j] == 'U'){
        ans = dfs(i - 1, j, n, m);
    }
    else if(v[i][j] == 'L'){
        ans = dfs(i, j - 1, n, m);
    }
    else if(v[i][j] == 'D'){
        ans = dfs(i + 1, j, n, m);
    }
    else if(v[i][j] == 'R'){
        ans = dfs(i, j + 1, n, m);
    }
    else{
        for(auto& [x, y] : dir){
            ans = ans || dfs(i + x, j + y, n, m);
        }
    }
    return dp[i][j] = ans;
}

void solve(){
    ll n, m; 
    cin >> n >> m;
    
    v.assign(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    

    vis.assign(n, vector<bool>(m, false));
    dp.assign(n, vector<int>(m, -1));
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dfs(i, j, n, m);
        }
    }
    

    int count_true = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j] == true){
                count_true++;
            }
        }
    }
    

    cout << count_true << "\n";
    
    v.clear();
    vis.clear();
    dp.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}