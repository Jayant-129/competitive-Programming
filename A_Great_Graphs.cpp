#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    ll n, q;
    cin >> n >> q;

    vector < ll > v(n, 0);
    for (auto & x: v) cin >> x;

    vector < vector < ll >> pre(n, vector < ll > (3, 0));
    for (int i = 0; i < n; i++) {
        pre[i][v[i] - 1]++;
        for (int j = 0; j < 3; j++) {
            if (i > 0) pre[i][j] += pre[i - 1][j];
        }
    }

    for (int i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;

        ll val = (y - x + 1);
        if (val % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        vector < int > v1(3, 0);
        for (int j = 0; j < 3; j++) {
            v1[j] = pre[y][j];
            if (x > 0) v1[j] -= pre[x - 1][j];
        }
        cout << v[0] << " " << v[1] << " " << v[2] << endl;;
        bool flag = true; ll h = val/2;
        ll val1 = v1[0] + v1[1];
        ll val2 = v1[1] + v1[2];
        ll val3 = v1[2] + v1[0];
        if(val1 == h && v1[2] == h){
            cout << "YES" << endl;
            continue;
        }
        else if(val2 == h && v1[0] == h){
            cout << "YES" << endl;
            continue;
        }
        else if(val3 == h && v1[1] == h){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
            continue;
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}