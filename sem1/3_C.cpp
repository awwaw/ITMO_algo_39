#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>

#define pb push_back
#define print(x) cout << x << '\n'
#define mp make_pair
#define ll long long

using namespace std;

const long double EPS = 1e-7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//#ifdef ONLINE_JUDGE
//    freopen("glasses.in", "r", stdin);
//    freopen("glasses.out", "w", stdout);
//#endif
    int n, l;
    cin >> n >> l;
    vector<long double> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    long double left = 0.0;
    long double right = (long double)l;
    long double mid;
    while (right - left > EPS) {
        mid = (right + left) / 2.0;
        long double x = mid;
        long double start, end;
        start = 0.0;
        end = min(x, (long double)pos[1]);
        vector<pair<long double, long double>> cuts;
        bool can = true;
        if (end < pos[0]) can = false;
        cuts.pb({start, end});
        for (int i = 1; i < n; i++) {
            start = cuts.back().second;
            if (i == n - 1) {
                if (start + x < l) {
                    can = false;
                    break;
                }
                cuts.pb({ start, start + x});
            }
            else {
                end = min(start + x, pos[i + 1]);
                if (end < pos[i]) {
                    can = false;
                    break;
                }
                else {
                    if (end > pos[i + 1]) {
                        can = false;
                        break;
                    }
                }
                cuts.pb({ start, end });
            }
        }
//        print(mid);
//        print(can);
//        for (auto cut : cuts) {
//            cout << cut.first << ' ' << cut.second << '\n';
//        }
//        print("~~~~~~~~~~~~");
        if (!can) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    print(fixed << setprecision(15) << left);
    return 0;
}
