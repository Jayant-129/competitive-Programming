#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, q;
    cin >> n >> m >> q;
    
    vector<ll> a(n);
    ll sum_a = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum_a += a[i];
    }
    
    const int OFFSET = 200000;
    vector<int> freqA(400001, 0);
    for(int i=0;i<n;i++){
        if(a[i] + OFFSET >=0 && a[i] + OFFSET <400001 ){
            freqA[a[i] + OFFSET ]++;
        }
    }
    
    vector<ll> b(m);
    ll sum_b =0;
    for(int i=0;i<m;i++){
        cin >> b[i];
        sum_b +=b[i];
    }
    
    sort(b.begin(), b.end());
    
    auto get_divisors = [&](ll x) -> vector<ll> {
        vector<ll> divisors;
        if(x ==0 ){
            return divisors;
        }
        ll abs_x = abs(x);
        for(ll d=1; d*d <= abs_x; d++){
            if(x % d ==0 ){
                divisors.emplace_back(d);
                divisors.emplace_back(-d);
                if(d != abs_x /d ){
                    divisors.emplace_back(x/d);
                    divisors.emplace_back(-x/d);
                }
            }
        }
        return divisors;
    };
    
    while(q--){
        ll x;
        cin >> x;
        bool ok = false;
        
        if(x ==0 ){
            if( (sum_a >= -200000 && sum_a <=200000 ) && freqA[sum_a + OFFSET ] >0 && m >=1 ){
                ok=true;
            }
            else{
                if(binary_search(b.begin(), b.end(), sum_b ) && n >=1 ){
                    ok=true;
                }
            }
        }
        else{
            vector<ll> divisors = get_divisors(x);
            for(auto d : divisors ){
                if(d ==0 ) continue;
                ll a_r = sum_a - d;
                if(a_r < -200000 || a_r >200000 ) continue;
                if(x % d !=0 ) continue;
                ll bc = sum_b - (x /d );
                if(bc < -200000 || bc >200000 ) continue;
                if(a_r + OFFSET <0 || a_r + OFFSET >=400001 ) continue;
                if(freqA[a_r +OFFSET ] ==0 ) continue;
                if(binary_search(b.begin(), b.end(), bc )){
                    ok=true;
                    break;
                }
            }
        }
        
        cout << (ok? "YES" : "NO") << "\n";
    }
    
    return 0;
}
