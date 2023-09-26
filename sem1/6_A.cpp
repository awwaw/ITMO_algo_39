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
    string s;
    string s1;
    cin >> s >> s1;
    int n = s.size();
    int m = s1.size();
    vector<vector<int>> lv(n + 1, vector<int>(m + 1, -1));
    lv[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        lv[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        lv[i][0] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == s1[j - 1]) {
                lv[i][j] = lv[i - 1][j - 1];
                continue;
            }
            lv[i][j] = min(lv[i][j - 1], min(lv[i - 1][j], lv[i - 1][j - 1])) + 1;
        }
    }
    print(lv[n][m]);
    return 0;
}
