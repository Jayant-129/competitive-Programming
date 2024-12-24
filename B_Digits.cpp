#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    
    while(t--){
        ll n, d;
        cin >> n >> d;
        
        vector<int> divisors;
        
        divisors.push_back(1);

        if(n >= 3 || d % 3 == 0){
            divisors.push_back(3);
        }
        
        if(d == 5){
            divisors.push_back(5);
        }
        
        if(n >= 3 || d == 7){
            divisors.push_back(7);
        }
        
        if(d == 9 || n >= 6 || (d % 3 == 0 && n >= 3)){
            divisors.push_back(9);
        }

        sort(divisors.begin(), divisors.end());
        
        for(auto divisor : divisors){
            cout << divisor << ' ';
        }
        cout << '\n';
    }
}