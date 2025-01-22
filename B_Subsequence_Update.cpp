#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for(auto &x : a) cin >> x;
        ll k = r - l + 1;
        
        vector<ll> sorted_first_r(a.begin(), a.begin() + r);
        sort(sorted_first_r.begin(), sorted_first_r.end());
        ll sum1 = 0;
        for(int i = 0; i < k && i < sorted_first_r.size(); i++) sum1 += sorted_first_r[i];
        vector<ll> sorted_from_l(a.begin() + l - 1, a.end());
        sort(sorted_from_l.begin(), sorted_from_l.end());
        ll sum2 = 0;
        for(int i = 0; i < k && i < sorted_from_l.size(); i++) sum2 += sorted_from_l[i];
        ll final_sum = min(sum1, sum2);
        cout << final_sum << "\n";
    }
}