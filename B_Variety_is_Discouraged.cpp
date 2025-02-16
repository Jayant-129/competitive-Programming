#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        vector<int> freq(n+1, 0);
        for (int i = 0; i < n; i++){
            freq[a[i]]++;
        }
 
        vector<bool> isUnique(n, false);
        for (int i = 0; i < n; i++){
            if(freq[a[i]] == 1)
                isUnique[i] = true;
        }
 
        int bestLen = 0, bestL = -1, bestR = -1;
        int start = -1;
        for (int i = 0; i < n; i++){
            if(isUnique[i]){
                if(start == -1) start = i;
            } else {
                if(start != -1){
                    int len = i - start;
                    if(len > bestLen){
                        bestLen = len;
                        bestL = start;
                        bestR = i - 1;
                    }
                    start = -1;
                }
            }
        }
        if(start != -1){
            int len = n - start;
            if(len > bestLen){
                bestLen = len;
                bestL = start;
                bestR = n - 1;
            }
        }
 
        if(bestLen > 0) {
            cout << bestL+1 << " " << bestR+1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}