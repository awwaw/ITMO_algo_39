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

vector<int> seq;
vector<int> buf;

bool cmp(int a, int b) {
    int dig1 = a % 10;
    int dig2 = b % 10;
    if (dig1 <= dig2)
        return true;
    return false;
}

void merge(int l1, int r1, int l2, int r2) {
    int ptr1 = l1;
    int ptr2 = l2;
    int ind = 0;
    while (ptr1 < r1 && ptr2 < r2) {
        if (cmp(seq[ptr1], seq[ptr2]))
            buf[ind++] = seq[ptr1++];
        else
            buf[ind++] = seq[ptr2++];
    }
    while (ptr1 < r1)
        buf[ind++] = seq[ptr1++];
    while (ptr2 < r2)
        buf[ind++] = seq[ptr2++];
    for (int i = 0; i < ind; i++)
        seq[i + l1] = buf[i];
}

void mergeSort(int l, int r) {
    if (l + 1 >= r)
        return;
    int m = (l + r) / 2;
    if (m - l > 1)
        mergeSort(l, m);
    if (r - m > 1)
        mergeSort(m, r);
    merge(l, m, m, r);
}

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    seq.resize(n);
    buf.resize(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    mergeSort(0, n);
    for (int t : seq)
        cout << t << ' ';
    cout << '\n';
    return 0;
}
