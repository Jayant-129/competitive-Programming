#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n, 0);
    ll cnt = 0;
    for (auto &x : v)
    {
        cin >> x;
        if (x % 2)
        {
            cnt++;
        }
    }
    if (cnt & 1)
    {
        ll val = n - cnt;
        if ((cnt / 2) & 1)
        {
            cout << "Alice" << endl;
            return;
        }
        else
        {
            if (val & 1)
            {
                cout << "Alice" << endl;
                return;
            }
            else
            {
                cout << "Bob" << endl;
                return;
            }
        }
    }
    if ((cnt / 2) & 1)
    {
        cout << "Bob" << endl;
        return;
    }
    else
    {
        cout << "Alice" << endl;
        return;
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}