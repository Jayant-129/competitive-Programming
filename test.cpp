#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll maxi = 0, x= 0, y= 0;
  for(int i = 1; i <= 10000; i++){
    for(int j = 1; j <= 10000; j++){
        ll val = __gcd(i,j);
        ll lcm = (i * j)/(val);
        if(lcm > maxi){
            maxi = lcm;
            x = i, y = j;
        }
    }
  }
  cout << maxi << " " << x << " " << y <<  endl;
}