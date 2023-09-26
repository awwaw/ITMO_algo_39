#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>

using namespace std;

#define print(x) cout << x << '\n'
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

vector<int> seq;
void sift_up(int v) {
    while (v != 0 && seq[(v - 1) / 2] < seq[v]) {
        swap(seq[(v - 1) / 2], seq[v]);
        v = (v - 1) / 2;
    }
}

void insert(int x) {
    seq.pb(x);
    sift_up(seq.size() - 1);
}

void sift_down(int v) {
    while (true) {
        int l = 2 * v + 1;
        int r = 2 * v + 2;
        int mx = v;
        if (l < seq.size() && seq[l] > seq[mx])
            mx = l;
        if (r < seq.size() && seq[r] > seq[mx])
            mx = r;
        if (mx == v)
            break;
        swap(seq[mx], seq[v]);
        v = mx;
    }
}

int extract_max() {
    int res = seq[0];
    swap(seq[0], seq.back());
    seq.pop_back();
    sift_down(0);
    return res;
}

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int x;
            cin >> x;
            insert(x);
        }
        else {
            print(extract_max());
        }
    }
    return 0;
}
