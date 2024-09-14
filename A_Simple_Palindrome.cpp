#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    int arr[5] = {0};
    for(int i = 0; i < 5; i++){
        arr[i] = n/5;
    }
    ll cnt = n % 5;
    for(int i = 0; i < cnt; i++){
        arr[i]++;
    }
    string base = "aeiou";
    for(int i = 0; i < 5; i++){
        for(int j =0; j < arr[i]; j++){
            cout << base[i];
        }
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
