#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 1e9;

int n, K, Q, d[N], c[N][N];
int y[N], x[N];
bool visited[N];
int load[N], nbr = 0, segments = 0, minc = INF, f = 0, minf = INF;

void input() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> c[i][j];
            if (i != j) minc = min(minc, c[i][j]);
        }
    }
    y[0] = 0;
    d[0] = 0;
}

bool check_x(int v, int k) {
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

bool check_bound() {
    if (f + (n + nbr - segments) * minc < minf) return true;
    return false;
}

void try_x(int s, int k) {
    if (s == 0) {
        if (k < K) try_x(y[k+1], k+1);
        return;
    }
    for (int v = 0; v <= n; ++v) {
        if (check_x(v, k)) {
            x[k] = v;
            visited[v] = true;
            load[k] += d[v];
            f += c[s][v];
            ++segments;
            if (v == 0) {
                if (k == K) {
                    if (segments == n + nbr) minf = min(minf, f);
                }
                else {
                    if (check_bound()) try_x(y[k+1], k+1);
                }
            }
            else {
                if (check_bound()) try_x(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            f -= c[s][v];
            --segments;
        }
    }
}

bool check_y(int v, int k) {
    if (v > 0 && visited[v]) return false;
    return true;
}

void try_y(int k) {
    int s = 0;
    if (y[k-1] > 0) s = y[k-1] + 1;
    for (int v = s; v <= n; ++v) {
        if (check_y(v, k)) {
            y[k] = v;
            visited[v] = true;
            load[k] += d[v];
            f += c[0][v];
            if (v > 0) {
                ++nbr; ++segments;
            }
            if (k == K) try_x(y[1], 1);
            else try_y(k+1);
            visited[v] = false;
            load[k] -= d[v];
            f -= c[0][v];
            if (v > 0) {
                --nbr; --segments;
            }
        }
    }
}

int main() {
    if (fopen(".inp", "r"))
        freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    try_y(1);
    cout << minf;

    return 0;
}