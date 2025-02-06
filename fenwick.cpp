#include<bits/stdc++.h>
using namespace std;
#define ll long long

class FenwickTree {
public:
    vector<ll> BIT;
    ll n;

    FenwickTree(ll size) {
        n = size;
        BIT.assign(n + 1, 0);
    }

    void update(ll index, ll value) {
        while (index <= n) {
            BIT[index] += value;
            index += index & -index;
        }
    }

    ll prefixSum(ll index) {
        ll sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }

    ll lowerBound(ll k) {
        ll sum = 0, pos = 0;
        for (ll i = 31; i >= 0; i--) {
            ll nextPos = pos + (1 << i);
            if (nextPos <= n && sum + BIT[nextPos] < k) {
                sum += BIT[nextPos];
                pos = nextPos;
            }
        }
        return pos + 1; 
    }

    ll upperBound(ll k) {
        ll sum = 0, pos = 0;
        for (ll i = 31; i >= 0; i--) {
            ll nextPos = pos + (1 << i);
            if (nextPos <= n && sum + BIT[nextPos] <= k) {
                sum += BIT[nextPos];
                pos = nextPos;
            }
        }
        return pos + 1; 
    }
};

int main(){
  ll n,m; cin >> n >> m;
  vector<ll> v(n);
  FenwickTree tree = new FenwickTree(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    tree.update(i,v[i]);
  }
  while(m--){
    char c; cin >> c;
    if(c == '!'){
        ll x, y; cin >> x >> y;
        ll val = y - v[x];
        tree.update(x,val);
    }
    else{
        ll x , y; 
        tree.lowerBound()
    }
  }

}