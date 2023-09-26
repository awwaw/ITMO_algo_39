#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

using namespace std;

#define print(x) cout << x << '\n';
#define pb push_back
#define mp make_pair
#define ll long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    ll left = 0;
    ll right = 1e18 + 1;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll newA = a + 2 * mid;
        ll newB = b + 2 * mid;
        ll cnt = (w / newA) * (h / newB);
        if (cnt < n) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    ll ans1 = left;

    left = 0;
    right = 1e18 + 1;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll newA = a + 2 * mid;
        ll newB = b + 2 * mid;
        ll cnt = (w / newB) * (h / newA);
        if (cnt < n) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    ll ans2 = left;

    print(max(ans1, ans2));
    return 0;
}
