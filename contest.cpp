#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 10000000000;
vector<bool> check(MAXN + 1, true);
vector<ll> prime;
void sieve() {
    check[0] = check[1] = false;
    for (ll i = 2; i * i <= MAXN; i++) {
        if (check[i]) {
            for (ll j = i * i; j <= MAXN; j += i) {
                check[j] = false;
            }
        }
    }
    for (ll i = 2; i <= MAXN; i++) {
        if (check[i]) prime.push_back(i);
    }
}

bool isPrime(ll n) {
    if (n <= MAXN) {
        return check[n];
    }
    return false;
}

ll nextPrime(ll n) {
    auto it = upper_bound(prime.begin(), prime.end(), n);
    if (it != prime.end()) return *it;
    else return -1;
}

ll largestPrimeFactor(ll n) {
    ll largest = -1;
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }
    if (n > 2) {
        largest = n;
    }
    return largest;
}

ll kval(ll n){
    if(isPrime(n)){
        return nextPrime(n);
    }
    if(n == 1){
        return 1;
    }
    return largestPrimeFactor(n);
}

ll solve(ll n){
    if(n < 10) {
        return n;
    }
    ll sum = 0;
    ll x = n;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    ll k = kval(n);
    return solve(sum + ((sum % 10) * k));
}

int main(){
    sieve();
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
