#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    sort(v.begin(),v.end());
    ll si=v.back(),ei=si+k-1;
    ll maxi=v.back(),mini=maxi+k-1;
    for(int i=0;i<n-1;i++){
        ll si=v.back(),ei=si+k,ans;
        if(((v.back()-v[i])/k) & 1){
            while(si<=ei){
                ll mid=(si+ei)/2;
                if(((mid-v[i])/k) & 1){
                    si=mid+1;
                }
                else{
                    ans=mid;
                    ei=mid-1;
                }
            }
            maxi=max(maxi,ans);
        }
        else{
            while(si<=ei){
                ll mid=(si+ei)/2;
                if(((mid-v[i])/k) & 1){
                    ei=mid-1;
                }
                else{
                    ans=mid;
                    si=mid+1;
                }
            }
            mini=min(mini,ans);
        }
    }
    if(maxi<=mini){
        cout<<maxi<<endl;
        return;
    }
    cout<<-1<<endl;
}
 
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}