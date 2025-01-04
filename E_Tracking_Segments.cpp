#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> segments(m);
        for(auto &p : segments) cin >> p.first >> p.second;
        int q;
        cin >> q;
        vector<int> changes(q);
        for(auto &x : changes) cin >> x;
        int left = 0, right = q + 1, answer = -1;
        while(left + 1 < right){
            int mid = left + (right - left)/2;
            vector<int> a(n+1, 0);
            for(int i=0; i<mid; ++i){
                a[changes[i]] = 1;
            }
            vector<int> prefix(n+1, 0);
            for(int i=1; i<=n; ++i){
                prefix[i] = prefix[i-1] + a[i];
            }
            bool found = false;
            for(auto &[l, r] : segments){
                int ones = prefix[r] - prefix[l-1];
                int zeros = (r - l +1) - ones;
                if(ones > zeros){
                    found = true;
                    break;
                }
            }
            if(found){
                answer = mid;
                right = mid;
            }
            else{
                left = mid;
            }
        }
        cout << answer << "\n";
    }
}