#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1000+5;
int n, x;
int D[N];

void input() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> D[i];
}

int minCoin(int i, int v) {
    if (v < 0 || i == 0) return INF;
    if (v == 0) return 0;
    int res = min(INF, 1 + minCoin(i, v-D[i]));
    res = min(res, minCoin(i-1, v));
    return res;
}

int main() {
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    cout << minCoin(n, x);
    return 0;
}