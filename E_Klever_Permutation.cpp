#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> ans;
    ll x=n-k;
    int a=(x+1)/2;
    int b=x/2;
    ans.push_back(1);
    ans.push_back(n);
    int k2=k/2;
    for(int i=1;i<k/2;i++){
        int adiff,bdiff;
        if(a%k2!=0){
            adiff=(a/k2)+1;
            a-=((a/k2)+1);
        }
        else{
            adiff=(a/k2);
            a-=((a/k2));
        }
        if(b%k2!=0){
            bdiff=(b/k2)+1;
            b-=((b/k2)+1);
        }
        else{
            bdiff=(b/k2);
            b-=((b/k2));
        }
        ans.push_back(ans[ans.size()-2]+adiff+1);
        ans.push_back(ans[ans.size()-2]-(bdiff+1));
        //cout << ans.size() << endl;
        k2--;
    }
    for(int i=k;i<n;i++){
        if(i%2==0)
        ans.push_back(ans[i-k]+1);
        else
        ans.push_back(ans[i-k]-1);
    }
    for(auto& i: ans){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
  ll t;
  cin >> t;
  while(t-- > 0){
    solve();
  }
}