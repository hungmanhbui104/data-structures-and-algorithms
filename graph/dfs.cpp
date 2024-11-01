#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
vector<int> adj[N];
bool visited[N];

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++)
        sort(adj[u].begin(), adj[u].end());
}

void DFS(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v: adj[u])
        if (!visited[v])
            DFS(v);
}

int main()
{
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    for (int u = 1; u <= n; u++)
        if (!visited[u]) DFS(u);

    return 0;
}
