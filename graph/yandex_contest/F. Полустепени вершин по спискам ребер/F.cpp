#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> in(n, 0);
    vector<int> out(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        out[u - 1]++;
        in[v - 1]++;
    }

    for (int i = 0; i < n; i++) {
        cout << in[i] << "\n" << out[i] << endl;
    }

    return 0;
}