#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

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
    int n;
    cin >> n;
    set<int> seq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        seq.insert(x);
    }
    int ans = 0;
    for (int t : seq) {
        if (t == ans)
            ans++;
        else {
            print(ans);
            return 0;
        }
    }
    print(ans);
    return 0;
}
