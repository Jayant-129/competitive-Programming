#include<bits/stdc++.h>
using namespace std;
map<long long, int> cnt;

long long get(int b, long long c) {
    long long D = 1LL * b * b - 4LL * c;
    if (D < 0) return 0;
    long long sqrt_D = (long long)sqrt(D);
    if (sqrt_D * sqrt_D != D) return 0; 
    long long x1 = (b - sqrt_D) / 2;
    long long x2 = (b + sqrt_D) / 2;
    if (x1 == x2) return 1LL * cnt[x1] * (cnt[x1] - 1) / 2LL;
    else return 1LL * cnt[x1] * cnt[x2];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        int q; cin >> q;
        for (int i = 0; i < q; i++) {
            int b; long long c;
            cin >> b >> c;
            cout << get(b, c) << " \n"[i == q - 1];
        }
    }
}

