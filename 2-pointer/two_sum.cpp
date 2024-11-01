#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n, M;
int a[N];
int Q = 0;

void input()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

int main()
{
    if (fopen("data.inp", "r"))
        freopen("data.inp", "r", stdin);

    input();
    sort(a+1, a+n+1);
    int i = 1, j = n;
    while (i < j)
    {
        if (a[i] + a[j] == M)
        {
            Q++;
            i++; j--;
        }
        else if (a[i] + a[j] < M) i++;
        else j--;
    }
    cout << Q;

    return 0;
}
