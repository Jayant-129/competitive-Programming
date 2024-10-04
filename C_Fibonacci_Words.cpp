#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s; cin >> s;
  for(int i = 2; i < s.length(); i++){
    int val  = ((s[i - 1] - 'A') + (s[i - 2] - 'A')) % 26;
    if(s[i] != (val + 'A')){
        cout << "NO" << endl;
        return 0;
    }
  }
  cout << "YES" << endl;
}