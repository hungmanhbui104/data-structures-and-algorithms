#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {};
};

struct DSU
{
    vector<int> p;

    void init(int n)
    {
        p.resize(n+5, 0);
        for (int v = 1; v <= n; v++) p[v] = v;
    }

    int find(int v)
    {
        if (p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    bool join(int u, int v)
    {
        u = find(u); v = find(v);
        if (u == v) return false;
        p[v] = u;
        return true;
    }
} dsu;

int N, M, totalWeight = 0;
vector<Edge> edges;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}

int main()
{
    if (fopen("data.inp", "r")) freopen("data.inp", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    dsu.init(N);
    sort(edges.begin(), edges.end(), [](Edge &x, Edge &y)
    {
        return x.w < y.w;
    });
    for (Edge e: edges)
    {
        if (!dsu.join(e.u, e.v)) continue;
        totalWeight += e.w;
    }
    cout << totalWeight;

    return 0;
}
