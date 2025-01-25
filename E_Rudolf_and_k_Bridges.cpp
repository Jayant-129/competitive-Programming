#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> getStatForRequests(int m, const vector<string>& database, const vector<string>& queries) {
    unordered_map<string, pair<int, string>> urlMap;
    for (const string &row : database) {
        istringstream iss(row);
        int userId;
        string shortUrl, actualUrl;
        iss >> userId >> shortUrl >> actualUrl;
        urlMap[shortUrl] = {userId, actualUrl};
    }
    vector<int> requestCount(m, 0);
    vector<vector<string>> result;
    
    for (const string &query : queries) {
        if (urlMap.find(query) != urlMap.end()) {
            int userId = urlMap[query].first;
            string actualUrl = urlMap[query].second;
            requestCount[userId]++;
            result.push_back({actualUrl, to_string(requestCount[userId])});
        } else {
            result.push_back({"", "0"});
        }
    }
    return result;
}

int main() {
    vector<string> database = {
        "0 ssf www.google.com",
        "1 juytf www.google.com",
        "0 opoit www.kaggle.com"
    };
    vector<string> queries = {"juytf", "ssf", "opoit"};
    
    vector<vector<string>> stats = getStatForRequests(3, database, queries);
    
    for (const auto &stat : stats) {
        cout << stat[0] << " " << stat[1] << "\n";
    }
    
    return 0;
}