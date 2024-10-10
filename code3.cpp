#include<bits/stdc++.h>
using namespace std;
int shift;
int solve(int i, vector<int>& v, vector<int>& f,vector<int>& m){ 
    if(i == m.size()){
        return 0;
    }
    int ans = INT_MAX;
    int curr = m[i];
    for(int j = 0; j < f.size(); j++){
        int val = f[j];
        f.erase(f.begin() + j);
        ans = abs(val - curr) + solve(i + 1,v,f,m);
        for(int k = 0; k < v.size(); k++){
            int val2 = v[k];
            v.erase(v.begin() + k);
            ans = min(ans,abs(val - (curr + val2)) + shift + solve(i + 1,v,f,m));
            v.insert(v.begin() + k,val2);
        }
        f.insert(f.begin() + j,val);
    }
    return ans;
}
int main(){
  shift = 3;
  int n = 5;
  vector<int> machine= {5,10,15,20,25};
  vector<int> final1={20,20,20};
  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        for(int k = j + 1; k < n; k++){
            vector<int> m = {machine[i],machine[j],machine[k]};
            vector<int> v;
            for(int l = 0; l < n; l++){
                if(l == i || l == j || l == k) continue;
                v.push_back(machine[l]);
            }
            int val = solve(0,v,final1,m);
            ans = min(ans,val);
        }
    }
  }
  cout << ans << endl;
}