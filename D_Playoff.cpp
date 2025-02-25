#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n; cin >> n;
  string s; cin >> s;
  ll cnt0 = 0, cnt1 = 0;
  for(auto& i: s){
    if(i == '0'){
        cnt0++;
    }
    else{
        cnt1++;
    }
  }
  ll val = ((cnt0 > 0)? 1: 0); ll  val2 = ((cnt1 > 0)? 1: 0);
  cnt0--; cnt1--;
  while(cnt0 > 0){
    val = 2 * val  + 1;
    cnt0--;
  }
  while(cnt1 > 0){
    val2 = 2 * val2  + 1;
    cnt1--;
  }
  for(int i = val2 + 1; (i <= pow(2,n) - (val)); i++){
    cout << i << " ";
  }
  cout << endl;
}