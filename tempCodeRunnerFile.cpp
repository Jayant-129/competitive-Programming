ll n; cin >> n;
    vector<ll> v(n, 0);
    for(auto& x: v) cin >> x;
    ll beg = 0;
    for(int i = 1; i < n; i++){
        if(v[i] != -v[0]){
            swap(v[i],v[1]);
            break;
        }
    }