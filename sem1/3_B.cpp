#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <map>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstring>
#include <cctype>

using namespace std;

#define print(x) cout << x << '\n'
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

#define int ll

vector<int> seq;

bool check(int dist, int k) {
    int last = seq[0];
    int cnt = 1;
    for (int i = 1; i < seq.size() && cnt < k; i++) {
        if (seq[i] - last >= dist) {
            cnt++;
            last = seq[i];
        }
    }
    return cnt == k;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    seq.resize(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    int left = 0;
    int right = seq.back();
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (check(mid, k))
            left = mid;
        else
            right = mid;
    }
    print(left);
    return 0;
}
