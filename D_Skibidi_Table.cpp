#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getNumber(int n, int x, int y, ll l, ll r) {
    if(n == 1){

        if(x == 1 && y == 1) return l;
        if(x == 2 && y == 2) return l + 1;
        if(x == 2 && y == 1) return l + 2;
        if(x == 1 && y == 2) return l + 3;
    }
    int side = 1 << n;     
    int half = 1 << (n-1); 
    ll total = r - l + 1;  
    ll block = total / 4; 
    
    int newX, newY;
    ll newL, newR;
    if(x <= half && y <= half){
        newL = l;
        newR = l + block - 1;
        newX = x;
        newY = y;
    }
    else if(x > half && y > half){
        newL = l + block;
        newR = l + 2*block - 1;
        newX = x - half;
        newY = y - half;
    }
    else if(x > half && y <= half){
        newL = l + 2*block;
        newR = l + 3*block - 1;
        newX = x - half;
        newY = y;
    }
    else { 
        newL = l + 3*block;
        newR = r;
        newX = x;
        newY = y - half;
    }
    return getNumber(n-1, newX, newY, newL, newR);
}

pair<int,int> getCoordinates(int n, ll d, ll l, ll r) {
    if(n == 1){
        if(d == l)      return {1, 1};
        if(d == l+1)    return {2, 2};
        if(d == l+2)    return {2, 1};
        if(d == l+3)    return {1, 2};
    }
    int side = 1 << n;
    int half = 1 << (n-1);
    ll total = r - l + 1;
    ll block = total / 4;
    int quad = 0;
    ll newL, newR;

    if(d >= l && d < l + block){
        quad = 1; 
        newL = l;
        newR = l + block - 1;
    }
    else if(d < l + 2*block){
        quad = 2;
        newL = l + block;
        newR = l + 2*block - 1;
    }
    else if(d < l + 3*block){
        quad = 3;
        newL = l + 2*block;
        newR = l + 3*block - 1;
    }
    else {
        quad = 4; 
        newL = l + 3*block;
        newR = r;
    }
    pair<int,int> sub = getCoordinates(n-1, d, newL, newR);
    int x, y;
    if(quad == 1){
        x = sub.first;
        y = sub.second;
    }
    else if(quad == 2){
        x = sub.first + half;
        y = sub.second + half;
    }
    else if(quad == 3){
        x = sub.first + half;
        y = sub.second;
    }
    else {
        x = sub.first;
        y = sub.second + half;
    }
    return {x, y};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        ll total = 1LL << (2*n);
        while(q--){
            string query;
            cin >> query;
            if(query == "->"){
                int x, y;
                cin >> x >> y;
                cout << getNumber(n, x, y, 1, total) << "\n";
            }
            else if(query == "<-"){
                ll d;
                cin >> d;
                pair<int,int> ans = getCoordinates(n, d, 1, total);
                cout << ans.first << " " << ans.second << "\n";
            }
        }
    }
    return 0;
}