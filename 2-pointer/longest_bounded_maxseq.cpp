#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n, Q;
int a[N];
int res = 0;

void input()
{
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

int main()
{
    if (fopen("data.inp", "r"))
        freopen("data.inp", "r", stdin);

    input();
    int i = 1, M = 0;
    for (int j = 1; j <= n; j++)
    {
        M += a[j];
        while (M > Q)
        {
            M -= a[i];
            i++;
        }
        res = max(res, j-i+1);
    }
    cout << res;

    return 0;
}
