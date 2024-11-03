#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll t,n,k,a[200100],i;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll max=0,sum=0,j,m,s;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
		for(j=1;j<=n;j++){
			m=(sum+k)/j;
			if(m>=max&&m*j>=sum){
				s=j;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}