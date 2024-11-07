#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vii = vector<ii>;
using vi = vector<lli>;
lli n, m;

void readInput(vii &a, lli n, lli m) {
    for (auto &x : a) cin >> x.first;
    for (auto &x : a) cin >> x.second;
}

void separateGroups(vii &a, lli n, lli m, vii &prog, vii &tester) {
    for (lli i = 0; i < n + m + 1; ++i) {
        const ii tester_candidate = {a[i].second, i}; 
        const ii prog_candidate = {a[i].first, i};  

        if (tester_candidate.first > prog_candidate.first) {
            if (tester.size() < m + 1)
                tester.push_back(tester_candidate); 
            else
                prog.push_back(prog_candidate);
        } else {
            if (prog.size() < n + 1)
                prog.push_back(prog_candidate);
            else
                tester.push_back(tester_candidate);
        }
    }
}

void calculateSumAndAdjustments(const vii &prog, const vii &tester, vi &ans, const vii &a) {
    lli sum = 0;
    for (const auto &x : prog) sum += x.first;  
    for (const auto &x : tester) sum += x.first; 

    fill(ans.begin(), ans.end(), sum); 

    if (prog.size() == n + 1) {
        for (const auto &x : prog) ans[x.second] -= x.first;
        lli adjustmentIndex = prog.back().second;
        lli det = a[adjustmentIndex].second - a[adjustmentIndex].first;
        for (const auto &x : tester) ans[x.second] += det - x.first;
    } else {
        for (const auto &x : tester) ans[x.second] -= x.first;
        lli adjustmentIndex = tester.back().second;
        lli det = a[adjustmentIndex].first - a[adjustmentIndex].second;
        for (const auto &x : prog) ans[x.second] += det - x.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        vii a(n + m + 1);
        readInput(a, n, m);

        vii prog, tester;
        separateGroups(a, n, m, prog, tester);

        vi ans(n + m + 1);
        calculateSumAndAdjustments(prog, tester, ans, a);

        for (lli i = 0; i < n + m + 1; ++i)
            cout << ans[i] << (i == n + m ? "\n" : " ");
    }
    return 0;
}
