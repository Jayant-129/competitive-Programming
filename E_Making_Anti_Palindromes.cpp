#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;

        // If the length is odd, it's impossible to form an anti-palindrome
        if(n % 2 != 0){
            cout << "-1\n";
            continue;
        }

        // Count frequency of each character in the string
        unordered_map<char, ll> freq;
        for(char c : s){
            freq[c]++;
        }

        // Check if any character appears more than n/2 times
        bool possible = true;
        for(auto &[c, count] : freq){
            if(count > n/2){
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << "-1\n";
            continue;
        }

        // Identify mismatched pairs where s[i] == s[n-i-1]
        vector<pair<ll, ll>> mismatches;
        for(ll i = 0; i < n/2; ++i){
            if(s[i] == s[n-i-1]){
                mismatches.emplace_back(i, n-i-1);
            }
        }

        ll k = mismatches.size();
        if(k == 0){
            // The string is already an anti-palindrome
            cout << "0\n";
            continue;
        }

        // Count frequency of each character in mismatched positions
        unordered_map<char, ll> mismatch_freq;
        for(auto &[i, j] : mismatches){
            mismatch_freq[s[i]]++;
        }

        // Find the maximum frequency among mismatched characters
        ll max_freq = 0;
        for(auto &[c, count] : mismatch_freq){
            if(count > max_freq){
                max_freq = count;
            }
        }

        // Calculate the minimum number of swaps required
        // The answer is the maximum between ceil(k / 2) and max_freq
        ll swaps = max( (k + 1) / 2 , max_freq );

        cout << swaps << "\n";
    }
}