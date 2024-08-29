#include<bits/stdc++.h>
using namespace std;

bool solve(string a,int idx){
    int p1 = 0;
    int p2 = idx;
    while(p2 != a.size()){
        if(a[p1] != a[p2]){
            return false;
        }
        p1++;
        p2++;
    }
    if(p1 > idx){
        return true;
    }
    return false;
}

int main(){
    string t;
    cin >> t;
    vector<int> v;
    for(int i = 1;i < t.size();i++){
        if(t[i] == t[0]){
            v.push_back(i);
        }
    }
    for(auto& i: v){
        if(solve(t,i)){
            cout << "YES" << endl;
            cout << t.substr(i) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}