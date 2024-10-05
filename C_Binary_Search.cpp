int function(vector<pair<int, int>>& coord_premium){
    int total_weight = 0; 
        for (const auto &cp : coord_premium) 
        { 
            total_weight += cp.second; 
        } 
 
        int sum = 0; 
        for (const auto &cp : coord_premium) 
        { 
            sum += cp.second; 
            if (sum >= (total_weight + 1) / 2) 
            { 
                return cp.first; 
            } 
        } 
        return 0; 
}
int windFarms(vector<int> premium, vector<int> x, vector<int> y) 
{ 
    int n = premium.size(); 
    vector<pair<int, int>> x_premium, y_premium; 
    for (int i = 0; i < n; ++i) 
    { 
        x_premium.push_back({x[i], premium[i]}); 
        y_premium.push_back({y[i], premium[i]}); 
    } 
 
 
    sort(x_premium.begin(), x_premium.end()); 
    sort(y_premium.begin(), y_premium.end()); 
    int cx = f(x_premium); 
    int cy = f(y_premium); 
    int total_cost = 0; 
    for (int i = 0; i < n; ++i) 
    { 
        total_cost += premium[i] * (abs(x[i] - cx) + abs(y[i] - cy)); 
    } 
 
    return total_cost; 
}