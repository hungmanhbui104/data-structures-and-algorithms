#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n;
ii X[N];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> X[i].first >> X[i].second;
}

int solve() {
    int i, j = 1, res = 1;
    for (i = 2; i <= n; ++i) {
        if (X[i].first > X[j].second) {
            ++res;
            j = i;
        }
    }
    return res;
}

int main() {
    if (fopen("data.inp", "r"))
        freopen("data.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sort(X+1, X+n+1, [](ii a, ii b) {
         return a.second < b.second;
    });
    cout << solve();

    return 0;
}
