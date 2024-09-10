#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b, s, c, pb, ps, pc, r,cntb,cnts,cntc;

bool good(ll mid){
    ll price = r;
    ll reqb = cntb * mid - b;
    ll reqs = cnts * mid - s;
    ll reqc = cntc * mid - c;
    if(reqb < 0){
        reqb = 0;
    }
    if(reqs < 0){
        reqs = 0;
    }
    if(reqc < 0){
        reqc = 0;
    }
    price -= (reqb*pb);
    price -= (reqc*pc);
    price -= (reqs*ps);
    return price >= 0;
}

int main(){
    string s1;
    cin >> s1 >> b >> s >> c >> pb >> ps >> pc >> r;
    cntb = 0, cntc = 0, cnts = 0;
    for(int i = 0; i < (int)s1.size(); i++){
        if(s1[i] == 'B'){
            cntb++;
        }
        else if(s1[i] == 'C'){
            cntc++;
        }
        else{
            cnts++;
        }
    }
    ll l = 0, r = (ll)1e13;
    while(l + 1 < r){
        ll mid = l + (r - l)/2;
        //cout << good(mid) << endl;
        if(good(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
}