#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int n, q, a[200001];
Tree<pii> o;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	FOR(i, 1, n + 1) {
		cin >> a[i];
		o.insert({a[i], i});
	}
	F0R(i, q) {
		char c;
		cin >> c;
		if (c == '!') {
			int x, y;
			cin >> x >> y;
			o.erase({a[x], x});
			a[x] = y;
			o.insert({a[x], x});
		} else {
			int x, y;
			cin >> x >> y;
			cout << o.order_of_key({y, MOD}) - o.order_of_key({x - 1, MOD}) << "\n";
		}
	}
}