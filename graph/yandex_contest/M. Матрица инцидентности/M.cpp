#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> incidentMatrix(N, vector<int>(M, 0));

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        incidentMatrix[u - 1][i] = 1;
        incidentMatrix[v - 1][i] = 1;
    }

    for (const auto& row : incidentMatrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j] << (j + 1 < row.size() ? " " : "\n");
        }
    }

    return 0;
}
