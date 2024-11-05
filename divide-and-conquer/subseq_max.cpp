#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int maxLeftMid(int l, int r) {
    int max = a[r], sum = 0;
    for (int i = r; i >= l; i--) {
        sum += a[i];
        if (sum > max) max = sum;
    }
    return max;
}

int maxRightMid(int l, int r) {
    int max = a[l], sum = 0;
    for (int i = l; i <= r; i++) {
        sum += a[i];
        if (sum > max) max = sum;
    }
    return max;
}

int subseqMax(int l, int r) {
    if (l == r) return a[l];
    int m = l + r >> 1;
    int maxL = subseqMax(l, m);
    int maxR = subseqMax(m+1, r);
    int maxM = maxLeftMid(l, m) + maxRightMid(m+1, r);
    return max(max(maxL, maxR), maxM);
}

int main() {
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    cout << subseqMax(0, n-1);

    return 0;
}