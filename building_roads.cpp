#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<pair<int, int>> findNewRoads(int n, int m, vector<pair<int, int>> roads) {
    DSU dsu(n);
    
    // Process existing roads
    for (auto road : roads) {
        dsu.unite(road.first, road.second);
    }

    // Find representatives of each connected component
    unordered_set<int> uniqueRoots;
    vector<int> representatives;
    
    for (int i = 1; i <= n; i++) {
        int root = dsu.find(i);
        if (uniqueRoots.find(root) == uniqueRoots.end()) {
            uniqueRoots.insert(root);
            representatives.push_back(root);
        }
    }

    // Build roads between representatives
    vector<pair<int, int>> newRoads;
    for (size_t i = 1; i < representatives.size(); i++) {
        newRoads.push_back({representatives[i - 1], representatives[i]});
    }

    return newRoads;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    vector<pair<int, int>> newRoads = findNewRoads(n, m, roads);
    
    cout << newRoads.size() << endl;
    for (auto road : newRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}
