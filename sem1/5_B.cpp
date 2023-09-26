#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << '\n'
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = table[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = -1;
            for (pair<int, int> move : { mp(-2, -1), mp(-1, -2) }) {
                int x = i + move.first;
                int y = j + move.second;
                if (0 <= x && x < n && 0 <= y && y < m && dp[x][y] != -1) {
                    mx = max(mx, dp[x][y]);
                }
            }
            if (mx != -1) {
                dp[i][j] = table[i][j] + mx;
            }
        }
    }
    print(dp[n - 1][m - 1]);
    return 0;
}
