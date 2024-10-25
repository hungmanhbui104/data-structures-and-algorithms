#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, Q;
int a[N];
int M[N];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

void computeM() {
    M[0] = 0;
    for (int i = 1; i <= n; ++i) M[i] = M[i-1] + a[i];
}

void querry() {
    cin >> Q;
    int i, j;
    for (int k = 0; k < Q; ++k) {
        cin >> i >> j;
        cout << M[j]- M[i-1] << endl;
    }
}

int main() {
    if (fopen("data.inp", "r"))
        freopen("data.inp", "r", stdin);

    input();
    computeM();
    querry();

    return 0;
}
