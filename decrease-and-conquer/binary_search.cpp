#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

bool binary_search(int l, int r, int v) {
    if (l > r) return false;
    int m = l + r >> 1;
    if (a[m] == v) return true;
    if (v < a[m]) return binary_search(l, m-1, v);
    return binary_search(m+1, r, v);
}

int main() {
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    cout << binary_search(0, n-1, -3);

    return 0;
}