#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x : a){
            cin >> x;
        }
        
        for(long long i =0; i < n-1; i++){
            if(a[i] <= a[i+1]){
                long long temp = a[i];
                a[i] = 0;
                a[i+1] -= temp;
            }
        }
        
        bool sorted_flag = true;
        for(long long i =0; i < n-1; i++){
            if(a[i] > a[i+1]){
                sorted_flag = false;
                break;
            }
        }
        
        if(sorted_flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}