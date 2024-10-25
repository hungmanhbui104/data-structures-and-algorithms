#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int n, m, Q;
int a[N][N];
int M[N][N] = {};

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
}

void computeM() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            M[i][j] = M[i-1][j] + M[i][j-1] - M[i-1][j-1] + a[i][j];
//            cout << "M" << i << j << " = " << M[i][j] << endl;
        }
    }
}

void querry() {
    cin >> Q;
    int r1, c1, r2, c2;
    for (int i = 0; i < Q; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << M[r2][c2] - M[r1-1][c2] - M[r2][c1-1] + M[r1-1][c1-1] << endl;
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
