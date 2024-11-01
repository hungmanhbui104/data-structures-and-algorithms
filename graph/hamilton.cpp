#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int T, n, m;
int x[N];
bool adj[N][N];
bool closed[N];
int res;

void input()
{
    cin >> n >> m;
    memset(adj, 0, sizeof(adj));
    memset(closed, 0, sizeof(closed));
    res = 0; x[1] = 1; closed[1] = true;
    int u, v;
    for (int j = 0; j < m; j++)
    {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }
}

void Try(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (adj[x[k-1]][v] && !closed[v])
        {
            x[k] = v;
            closed[v] = true;
            if (k == n)
            {
                if (adj[v][1])
                    res = 1;
            }
            else
                Try(k+1);
            closed[v] = false;
        }
    }
}

int main()
{
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        input();
        Try(2);
        cout << res << endl;
    }

    return 0;
}
