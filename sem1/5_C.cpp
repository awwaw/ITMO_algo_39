#define GLIBCXX_DEBUG_

#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <cmath>

using namespace std;

#define ll long long
#define pb push_back
#define print(x) cout << x << '\n'
#define mp make_pair
#define ld long double
#define INF INT64_MAX

const int MOD = 998244353;
const int P = 239;

const ld eps = 1e-7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> weight(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c = cost[i - 1];
            int w = weight[i - 1];
            if (j >= w) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + c);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int x = n;
    int y = m;
    vector<int> ans;
    while (dp[x][y] != 0) {
        if (dp[x - 1][y] == dp[x][y]) {
            x--;
        }
        else {
            ans.pb(x);
            y -= weight[x - 1];
            x--;
        }
    }
    print(ans.size());
    sort(ans.begin(), ans.end());
    for (int t : ans) {
        cout << t << ' ';
    }
    cout << '\n';
    return 0;
}
