#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << '\n'
#define pb push_back
#define mp make_pair

vector<pair<int, int>> edges;

struct query {
    string type;
    int a, b;

    query() {};

    query(string _type, int _a, int _b) : type(_type), 
                                            a(_a),
                                            b(_b) {};
};

istream& operator >>(istream& in, query& q) {
    return in >> q.type >> q.a >> q.b;
}

vector<int> ranks;
vector<int> p;

void init(int n) {
    ranks.assign(n, 0);
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
}

int get_root(int n) {
    return p[n] == n ? n : p[n] = get_root(p[n]);
}

void merge(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (ranks[b] > ranks[a]) swap(a, b);
    if (ranks[a] == ranks[b]) ranks[a]++;
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.pb(mp(a - 1, b - 1));
    }
    vector<query> queries(k);
    for (int i = 0; i < k; i++) {
        cin >> queries[i];
    }
    reverse(queries.begin(), queries.end());
    init(n);
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        query cur = queries[i];
        if (cur.type == "cut") {
            merge(cur.a - 1, cur.b - 1);
        }
        else {
            ans.pb(
                get_root(cur.a - 1) == get_root(cur.b - 1) ? "YES" : "NO"
            );
        }
    }
    reverse(ans.begin(), ans.end());
    for (string a : ans) {
        print(a);
    }
    return 0;
}
