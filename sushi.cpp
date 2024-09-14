#include<bits/stdc++.h>
using namespace std;
#define d long double
d dp[301][301][301];
// dp[x][y][z] = 1 + p3 * (d[x-1][y + 1][z]) + p2 * (d[x][y-1][z + 1]) + p2 *(d[x][y][z-1])
int main(){
  d n; cin >> n; int cnt[4] = {0}; for(int i = 0; i < n; i++){int x; cin >> x; cnt[x]++;}
  dp[0][0][0] = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      for(int k = 0; k <= n; k++){
        if(i == 0 && j == 0 && k == 0){
            continue;
        }
        if(i + j + k > n){
            continue;
        }
        d val = 1.0;
        if(i > 0) val += (i/n) * (dp[i-1][j + 1][k]);
        if(j > 0) val += (j/n) * (dp[i][j - 1][k + 1]);
        if(k > 0) val += (k/n) * (dp[i][j][k- 1]);
        dp[i][j][k] = val/(1 - (n-(i + j + k))/n);
      }
    }
  }

  cout << setprecision(10)<< fixed << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
}