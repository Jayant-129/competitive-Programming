#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    ll cnt = 0;

    for(int i = 0; i < s.size(); i++) {
        int single_digit = s[i] - '0';
        if(single_digit % 4 == 0) {
            cnt++;
        }
        if(i > 0) {
            int two_digit = (s[i-1] - '0') * 10 + (s[i] - '0');
            if(two_digit % 4 == 0) {
                cnt += i;
            }
        }
    }
    cout << cnt << endl;
}
