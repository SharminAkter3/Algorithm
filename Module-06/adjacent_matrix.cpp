#include <bits/stdc++.h>
using namespace std;
void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdin);
#endif // ONLINE_JUDGE
}

const int N = 1e3 + 5;
int adjmat[N][N];

int main()
{
    init_code();

    int n, m; // n= number of nodes, m= number of edges
    cin >> n >> m;

    // input
    for (int i = 0; i < m; i++) // number of edges golo input nibo
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = w; // directed holy
        adjmat[v][u] = w; // undirected holy
    }

    // output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}