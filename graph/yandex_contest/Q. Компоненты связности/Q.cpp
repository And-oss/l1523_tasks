#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int N;
    vector<vector<int>> adj;
    vector<int> component;

    void dfs(int v, int comp) {
        component[v] = comp;
        for (int u : adj[v]) {
            if (component[u] == 0) {
                dfs(u, comp);
            }
        }
    }

public:
    Graph(int n) : N(n), adj(n), component(n, 0) {}

    void addEdge(int a, int b) {
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    void findComponents() {
        int compCount = 0;
        for (int i = 0; i < N; ++i) {
            if (component[i] == 0) {
                ++compCount;
                dfs(i, compCount);
            }
        }

        cout << compCount << endl;
        for (int i = 0; i < N; ++i) {
            cout << component[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        g.addEdge(A, B);
    }

    g.findComponents();

    return 0;
}
