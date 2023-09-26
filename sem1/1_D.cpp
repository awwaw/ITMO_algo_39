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

#define int ll

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    int sum = 0;
    for (int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	events.pb({a, 1});
    	events.pb({b, -1});
    	sum += a;
    }
    sort(events.begin(), events.end());

    int balance = 0;
    int doesntCount = 0;
    int willOpen = n;
    int mx = 0;
    int ans = -1;
    for (int i = 0; i < events.size(); i++) {
    	auto e = events[i];
    	if (e.second == 1) {
    		balance += 1;
    		willOpen--;
    		sum -= e.first;
    	}
    	int open = balance;
    	int cost = open * e.first + sum;
    	if (mx < cost) {
    		mx = cost;
    		ans = e.first;
    	}
 	    if (e.second == -1)
 	    	balance--;
 	    doesntCount += (e.second == -1);
    }
    cout << ans << ' ' << mx << '\n';
    return 0;
}
