// all pair shortest path ber kory ..... potek ta node theky onno sob golo r shortest path ber korby
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int d[N][N];
int n, m;

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
                cout << "X ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

void dist_intitialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                d[i][j] = INF;
        }
    }
}

int main()
{
    cin >> n >> m;

    dist_intitialize();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        // d[v][u] = w; // undirected holy
    }

    print_matrix();

    for (int k = 1; k <= n; k++) // loop ta level er jnn
    {
        for (int i = 1; i <= n; i++) // baki ai dui ta pottek dui jon er moddy improve korar jnn
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << endl
         << "After applying Floyd Warshall" << endl;

    print_matrix();

    return 0;
}