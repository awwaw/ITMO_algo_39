#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define print(x) cout << x << '\n'
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    vector<int> seq(r * c);
    for (int i = 0; i < r * c; i++)
        cin >> seq[i];
    sort(seq.begin(), seq.end());
    int mx = 0;
    for (int i = 0; i + c - 1 < r * c; i += c) {
        mx = max(mx, seq[i + c - 1] - seq[i]);
    }
    print(mx);
    return 0;
}
