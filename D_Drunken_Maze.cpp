#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++){
        cin >> maze[i];
        for (int j = 0; j < m; j++){
            if(maze[i][j] == 'S'){
                sx = i; sy = j;
            }
            if(maze[i][j] == 'T'){
                tx = i; ty = j;
            }
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<vector<vector<bool>>>> visited(
        n, vector<vector<vector<bool>>>(
            m, vector<vector<bool>>(4, vector<bool>(4, false))));

    struct State { int i, j, d, cnt, steps; };
    deque<State> dq;
    
    for (int d = 0; d < 4; d++){
        int ni = sx + dx[d], nj = sy + dy[d];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (maze[ni][nj] == '#') continue;
        visited[ni][nj][d][1] = true;
        dq.push_back({ni, nj, d, 1, 1});
    }
    
    int ans = -1;
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        int i = cur.i, j = cur.j, d = cur.d, cnt = cur.cnt, steps = cur.steps;
        if(maze[i][j] == 'T'){
            ans = steps;
            break;
        }
        for (int nd = 0; nd < 4; nd++){
            int ni = i + dx[nd], nj = j + dy[nd];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(maze[ni][nj] == '#') continue;
            int ncnt = (nd == d ? cnt + 1 : 1);
            if(ncnt > 3) continue;
            if(!visited[ni][nj][nd][ncnt]){
                visited[ni][nj][nd][ncnt] = true;
                dq.push_back({ni, nj, nd, ncnt, steps + 1});
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}