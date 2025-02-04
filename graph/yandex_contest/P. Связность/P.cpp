#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj;
unordered_set<int> visited;

void dfs(int v) {
    stack<int> s;
    s.push(v);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);


            for (int neighbor : adj[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1);

    if (visited.size() == N) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
