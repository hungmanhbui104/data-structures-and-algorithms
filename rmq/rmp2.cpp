#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int I = log2(N)+5;
int n, m;
int a[N];
int M[I][N];
int Q = 0;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void computeM()
{
    for (int j = 0; j < n; j++)
        M[0][j] = j;
    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
//             a[M[i-1][j]] < a[M[i-1][j+2^(i-1)]
            if (a[M[i-1][j]] < a[M[i-1][j+(1<<(i-1))]])
                M[i][j] = M[i-1][j];
            else
                M[i][j] = M[i-1][j +(1<<(i-1))];
        }
    }

}

int rmq(int i, int j)
{
    int k = log2(j - i + 1);
//    a[M[k][i]] < a[M[k][j-2^k+1]
    if (a[M[k][i]] < a[M[k][j-(1<<k)+1]])
        return M[k][i];
    else
        return M[k][j-(1<<k)+1];
}

void querry()
{
    cin >> m;
    int i, j;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        Q += a[rmq(i, j)];
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
