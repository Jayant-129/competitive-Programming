#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x :a) cin >>x;
        vector<ll> evens, odds;
        for(auto x :a){
            if(x %2 ==0) evens.push_back(x);
            else odds.push_back(x);
        }
        // Optional: sort for predictable behavior
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        int p_e =0, p_o=0;
        ll s=0;
        int points=0;
        while(p_e < evens.size() || p_o < odds.size()){
            if(s %2 ==0){
                if(p_e < evens.size()){
                    s += evens[p_e];
                    points++;
                    p_e++;
                    // Set s to odd by dividing by 2 until odd
                    while(s %2 ==0 && s !=0){
                        s /=2;
                    }
                }
                else if(p_o < odds.size()){
                    s += odds[p_o];
                    if(s %2 ==0){
                        points++;
                        // Set s to odd
                        while(s %2 ==0 && s !=0){
                            s /=2;
                        }
                    }
                    p_o++;
                }
            }
            else{
                if(p_o < odds.size()){
                    s += odds[p_o];
                    if(s %2 ==0){
                        points++;
                        // Set s to odd
                        while(s %2 ==0 && s !=0){
                            s /=2;
                        }
                    }
                    p_o++;
                }
                else if(p_e < evens.size()){
                    s += evens[p_e];
                    if(s %2 ==0){
                        points++;
                        // Set s to odd
                        while(s %2 ==0 && s !=0){
                            s /=2;
                        }
                    }
                    p_e++;
                }
            }
        }
        cout << points << "\n";
    }
}