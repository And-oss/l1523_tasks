#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int table[100][100];
    int dp[100][100];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> table[i][j];
        }
    }

    dp[0][0] = table[0][0];

    for (int j = 1; j < M; ++j) {
        dp[0][j] = dp[0][j - 1] + table[0][j];
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + table[i][0];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + table[i][j];
        }
    }

    cout << dp[N - 1][M - 1] << endl;

    return 0;
}