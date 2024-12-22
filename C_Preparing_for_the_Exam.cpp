#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        
        vector<ll> a(m);
        for(auto &x : a) cin >> x;
        
        
        vector<ll> q(k);
        for(auto &x : q) cin >> x;
        
        if(k == n){
            // Monocarp knows all questions, passes all lists
            string res(m, '1');
            cout << res << "\n";
            continue;
        }
        else if(k == n-1){
            ll total_sum = (n * (n +1)) /2;
            ll sum_q = 0;
            for(auto x : q) sum_q += x;
            ll missing = total_sum - sum_q;
            string res;
            for(auto ai : a){
                if(ai == missing) res += '1';
                else res += '0';
                cout << res << endl;
            }
            cout << res << "\n";
        }
        else{
            // Monocarp knows less than n-1 questions, cannot pass any list
            string res(m, '0');
            cout << res << "\n";
        }
    }
}