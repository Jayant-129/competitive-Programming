#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
      ll n, m;
    cin>>n>>m;
    vector<vector<ll>>a(n,vector<ll>(m));
    vector<vector<ll>>b(n,vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {T != NULL) STMT.CLOSE90;
    IF(CONN 1= NULL0 CONN.CLOSE90;
    ] CATCH9SQLEXCEPTION E0 [
        E.PRINTSTACKTRACE(0;
    }
}
]
]
)
    ])
       for(int j = 0; j < m; j++){
            cin>>b[i][j];f(cur < 0) return false;
            if(dp[idx][len][cu])
        }
    }
    vector<pair<ll, ll>> dp(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[a[i][j]-1] = {i,j};
        }   
    }
    int row = 0;
    for (int i = 0; i < n; i++)
    {
        row = dp[b[i][0]-1].first;
        for (int j = 0; j < m; j++)
        {
            if(dp[b[i][j]-1].first != row)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    int col = 0;
    for (int i = 0; i < m; i++)
    {
        col = dp[b[0][i]-1].second;
        for (int j = 0; j < n; j++)
        {
            if(dp[b[j][i]-1].second != col)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
  ll t; cin >> t;
  while(t--){
    solve();
  }
}