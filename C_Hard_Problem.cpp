#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; 
    cin >> t;
    while(t--){
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll row1 = min(a, m); 
        ll row2 = min(b, m); 
        ll remainingSeats = 2 * m - row1 - row2;
        ll noPreference = min(c, remainingSeats);
        ll totalSeated = row1 + row2 + noPreference;

        cout << totalSeated << endl;
    }
    return 0;
}