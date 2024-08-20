#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

lli ar[5001][5001];
lli res[5001][5001];

int main()
{
	int n , l , r , q;
	cin>>n;
	
	REP(i , n) cin>>ar[1][i] , res[1][i] = ar[1][i];
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			ar[i][j] = ar[i-1][j] ^ ar[i-1][j+1];
			res[i][j] = max(ar[i][j] , max(res[i-1][j] , res[i-1][j+1]));
		}
	}
	
	cin>>q;
	
	while(q--){
		cin>>l>>r;
		
		int row = r - l + 1;
		int col = l;
		
		cout<<res[row][col]<<endl;
	}
}