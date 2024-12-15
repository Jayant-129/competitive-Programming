#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    while(t--){
        string s; 
        cin >> s;
        string ans = "";
        for(auto& i: s){
            if(i == 'p'){
                ans += "q";
            }
            else if(i == 'q'){
                ans += "p";
            }
            else if(i == 'w'){
                ans += "w";
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}