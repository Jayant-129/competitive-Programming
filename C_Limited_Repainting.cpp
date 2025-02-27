#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool canAchieve(int m, int k, const string &s, const vector<int> &penalties) {
    int n = s.size();
    int opsNeeded = 0;
    bool inSegment = false;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'R' && penalties[i] > m) {
            if(inSegment) { 
                opsNeeded++;
                inSegment = false;
            }
            continue;
        }
        if(s[i] == 'B' && penalties[i] > m) {
            if(!inSegment) {
                inSegment = true;
            }
        }
    }
    if(inSegment) opsNeeded++;
    return (opsNeeded <= k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> penalties(n);
        int maxPenalty = 0;
        for (int i = 0; i < n; i++){
            cin >> penalties[i];
            maxPenalty = max(maxPenalty, penalties[i]);
        }
        int lo = 0, hi = maxPenalty, ans = hi;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(canAchieve(mid, k, s, penalties)){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
      
        cout << ans << "\n";
    }
  
    return 0;
}