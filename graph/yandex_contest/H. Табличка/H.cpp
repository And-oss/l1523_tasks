#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, INF));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
