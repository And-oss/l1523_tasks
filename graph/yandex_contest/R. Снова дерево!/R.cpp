#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int N, M;
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int v, int parent) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                if (!dfs(u, v)) return false;
            } else if (u != parent) {
                return false;
            }
        }
        return true;
    }

public:
    Graph(int n, int m) : N(n), M(m), adj(n), visited(n, false) {}

    void addEdge(int a, int b) {
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    bool isTree() {
        if (M != N - 1) return false;
        if (!dfs(0, -1)) return false;
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N, M);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        g.addEdge(A, B);
    }

    cout << (g.isTree() ? "YES" : "NO") << endl;

    return 0;
}