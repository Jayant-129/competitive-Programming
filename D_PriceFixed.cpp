#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(const pair<ll,ll>& p1,const pair<ll,ll>& p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}
int main(){
  ll n; cin >> n;
  vector<pair<ll,ll>> v(n);
  for(int i = 0; i < n; i++){
    ll x,y; cin >> x >> y; 
    v[i] = {x,y};
  }
  sort(v.begin(),v.end(),comp);
  ll st = 0, e = n - 1, cnt = 0, price = 0;
  while(st < e){
    if(cnt < v[st].second){
        ll diff = v[st].second - cnt;
        if(diff >= v[e].first){
            price += (2 * v[e].first);
            cnt += v[e].first;
            diff -= v[e].first;
            v[e].first = 0;
            e--;
        }
        else{
            price += (2 * diff);
            cnt += diff;
            v[e].first -= diff;
        }
    }
    else{
        price += (v[st].first);
        cnt += (v[st].first);
        v[st].first = 0;
        st++;
    }
    //cout << price << " " << cnt << " " << st << " " << e << endl;
  }
  //cout << price << " " << cnt <<  endl;
  //cout << st << " " << e << " " << v[st].first << endl;
  if(st == e && v[st].first > 0){
    if(cnt >= v[st].second){
        price += v[st].first;
    }
    else{
        ll diff = v[st].second - cnt;
        if(diff >= v[st].first){
            price += (2 * v[st].first);
        }
        else{
            price += (2 * diff);
            v[st].first -= diff;
            price += (v[st].first);
        }
    }
  }
  cout << price << endl;
}