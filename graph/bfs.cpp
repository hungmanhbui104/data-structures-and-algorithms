#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
vector<int> adj[N];
queue<int> q;
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

void BFS(int u)
{
    q.push(u);
    visited[u] = true;
    int v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int w: adj[v])
        {
            if (!visited[w])
            {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

int main()
{
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);

    input();
    for (int u = 1; u <= n; u++)
        if (!visited[u]) BFS(u);

    return 0;
}

