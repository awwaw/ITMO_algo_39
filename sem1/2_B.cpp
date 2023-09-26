#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <map>

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
    set<int> free;
    for (int i = 0; i < n; i++)
        free.insert(i);
    map<int, int> ind;
    char type;
    int cur;
    vector<pair<int, int>> ans;
    while (cin >> type >> cur) {
        if (type == '+') {
            if (free.empty())
                return cout << "0 " << cur, 0;
            int place = *free.begin();
            free.erase(free.begin());
            ind[cur] = place;
            ans.pb({cur, place + 1});
        }
        else {
            int place = ind[cur];
            free.insert(place);
        }
    }
    for (auto p : ans)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
