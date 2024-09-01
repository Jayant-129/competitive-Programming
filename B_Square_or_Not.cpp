#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPerfectSquare(ll num) {
    if (num < 0) return false;
    ll root = round(sqrt(num));
    return root * root == num;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(!isPerfectSquare(n)){
        cout << "No" << endl;
    }
    else{
        bool flag = true;
        ll root = round(sqrt(n));
        for(int i = 0; i < root; i++){
            if(s[i] != '1'){
                flag = false;
            }
        }
        for(int i = n - root; i < n; i++){
            if(s[i] != '1'){
                flag = false;
            }
        }
        for(int i = root; i < (n - root); i += root){
            if(s[i] != '1' || s[i + root - 1] != '1'){
                flag = false;
            }
            ll cnt = 0;
            for(int j = i + 1; j < i + root; j++){
                if(s[j] == '0'){
                   cnt++;
                }
            }
            if(cnt == 0){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}

int main(){
    ll t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
}