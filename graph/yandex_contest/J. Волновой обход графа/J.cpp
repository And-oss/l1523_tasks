#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj;
vector<int> path;
unordered_set<int> visited;


void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited.insert(v);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        path.push_back(current);

        for (int neighbor : adj[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int N, M, v;
    cin >> N >> M >> v;

    adj.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    bfs(v);

    cout << path.size() << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
