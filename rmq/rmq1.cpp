#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n, m;
int a[N];
int M[N][N];
int Q = 0;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void computeM()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j) M[i][i] = i;
            else if (a[M[i][j-1]] < a[j]) M[i][j] = M[i][j-1];
            else M[i][j] = j;
        }
    }
}

void querry()
{
    cin >> m;
    int i, j;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;

        Q += a[M[i][j]];
    }
}

int main()
{
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    computeM();
    querry();
    cout << Q;

    return 0;
}
