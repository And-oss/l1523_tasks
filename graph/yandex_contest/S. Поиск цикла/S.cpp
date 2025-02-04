#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 100005;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<bool> inStack(N, false);
vector<int> parent(N, -1);
int cycle_start = -1, cycle_end = -1;

bool dfs(int v) {
    visited[v] = true;
    inStack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            parent[u] = v;
            if (dfs(u)) return true;
        } else if (inStack[u]) {
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }

    inStack[v] = false;
    return false;
}

void find_cycle(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i)) break;
    }
    if (cycle_start == -1) {
        cout << "NO";
        return;
    }

    vector<int> cycle;
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);

    cout << "YES\n";
    for (int i = cycle.size() - 1; i >= 0; --i) {
        cout << cycle[i] << ' ';
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    find_cycle(n);
    return 0;
}
