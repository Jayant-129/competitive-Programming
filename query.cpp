#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N;
vector<ll> v, Tree, Lazy;

void buildTree(ll tidx, ll lo, ll hi) {
    if (lo == hi) {
        Tree[tidx] = v[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    buildTree(2 * tidx + 1, lo, mid);
    buildTree(2 * tidx + 2, mid + 1, hi);
    Tree[tidx] = Tree[2 * tidx + 1] + Tree[2 * tidx + 2];
}

void propagate(ll tidx, ll lo, ll hi) {
    if (Lazy[tidx] != 0) {
        Tree[tidx] += (hi - lo + 1) * Lazy[tidx];
        if (lo != hi) {
            Lazy[2 * tidx + 1] += Lazy[tidx];
            Lazy[2 * tidx + 2] += Lazy[tidx];
        }
        Lazy[tidx] = 0;
    }
}

void updateTree(ll tidx, ll lo, ll hi, ll L, ll R, ll val) {
    propagate(tidx, lo, hi);
    if (R < lo || L > hi) return;
    if (lo >= L && hi <= R) {
        Lazy[tidx] += val;
        propagate(tidx, lo, hi);
        return;
    }
    ll mid = (lo + hi) / 2;
    updateTree(2 * tidx + 1, lo, mid, L, R, val);
    updateTree(2 * tidx + 2, mid + 1, hi, L, R, val);
    Tree[tidx] = Tree[2 * tidx + 1] + Tree[2 * tidx + 2];
}

ll query(ll tidx, ll lo, ll hi, ll L, ll R) {
    propagate(tidx, lo, hi);
    if (R < lo || L > hi) return 0;
    if (lo >= L && hi <= R) return Tree[tidx];
    ll mid = (lo + hi) / 2;
    ll leftans = query(2 * tidx + 1, lo, mid, L, R);
    ll rightans = query(2 * tidx + 2, mid + 1, hi, L, R);
    return leftans + rightans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q;
    cin >> N >> q;

    v.resize(N);
    Tree.resize(4 * N, 0);
    Lazy.resize(4 * N, 0);

    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }

    buildTree(0, 0, N - 1);

    while (q--) {
        ll type, a, b, val;
        cin >> type >> a;
        if (type == 1) {
            cin >> b >> val;
            updateTree(0, 0, N - 1, a - 1, b - 1, val);
        } else if (type == 2) {
            cout << query(0, 0, N - 1, a - 1, a - 1) << "\n";
        }
    }
    return 0;
}