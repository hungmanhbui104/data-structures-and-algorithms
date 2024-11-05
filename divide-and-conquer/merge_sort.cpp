#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void merge(int l, int m, int r) {
    int len = r - l + 1;
    int tmp[len];
    int i = 0, i1 = l, i2 = m+1;
    for (; i1 <= m && i2 <= r; i++) {
        if (a[i1] < a[i2]) tmp[i] = a[i1++];
        else tmp[i] = a[i2++];
    }
    for (; i1 <= m; i++, i1++) tmp[i] = a[i1];
    for (; i2 <= r; i++, i2++) tmp[i] = a[i2];
    for (i = 0; i < len; i++) a[l+i] = tmp[i];
}

void merge_sort(int l, int r) {
    if (l < r) {
        int m = l + r >> 1;
        merge_sort(l, m);
        merge_sort(m+1, r);
        merge(l, m, r);
    }
}

void printArray() {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}


int main() {
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    merge_sort(0, n-1);
    printArray();

    return 0;
}