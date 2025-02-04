#include <iostream>
#include <vector>

using namespace std;

void dfs(int city, vector<vector<int>> &graph, vector<bool> &visited, int N) {
    visited[city] = true;
    for (int neighbor = 0; neighbor < N; neighbor++) {
        if (graph[city][neighbor] > 0 && !visited[neighbor]) {
            dfs(neighbor, graph, visited, N);
        }
    }
}

int countCountries(int N, vector<vector<int>> &graph) {
    vector<bool> visited(N, false);
    int countries = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            countries++;
            dfs(i, graph, visited, N);
        }
    }

    return countries;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    cout << countCountries(N, graph) << endl;
    return 0;
}