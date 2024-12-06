#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int cnt2 = 0, cnt3 = 0, sum = 0;
    for(auto& i: s){
        if(i == '2'){
            cnt2++;
        }
        else if(i == '3'){
            cnt3++;
        }
        sum += (i - '0');
    }
    if(cnt2 >= 10 && cnt3 >= 10){
        cout << "YES" << endl; 
        return;
    }
    else{
        for(int i = 0; i <= cnt2; i++){
            for(int j = 0; j <= cnt3; j++){
                int val = i*2 + j*6 + sum;
                if(val % 9 == 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
    }
}

int main(){
  int t; cin >> t;
  while(t--){
    solve();
  }
}
