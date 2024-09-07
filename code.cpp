#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n , q; cin >> n >> q;
    string s; cin >> s;
    ll cnt = 0;
    for(int i = 0; i < (n - 2); i++){
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
            cnt++;
        }
    }
    //cout << cnt << endl;
    while(q-- > 0){
        ll x; char c; cin >> x >> c; x =  x - 1;
        if(x < (n - 2) && s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C'){
            cnt--;
        }
        else if(x < (n - 1) && x > 0 && s[x] == 'B' && s[x - 1] == 'A' && s[x + 1] == 'C'){
            cnt--;
        }
        else if(x > 1 && s[x] == 'C' && s[x - 1] == 'B' && s[x - 2] == 'A'){
            cnt--;
        }
        s[x] = c;
        if(x < (n - 2) && s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C'){
            cnt++;
        }
        else if(x < (n - 1) && x > 0 && s[x] == 'B' && s[x - 1] == 'A' && s[x + 1] == 'C'){
            cnt++;
        }
        else if(x > 1 && s[x] == 'C' && s[x - 1] == 'B' && s[x - 2] == 'A'){
            cnt++;
        }
        cout << cnt << endl;
    }
}