#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7;
int main()
{
    int n, e;
    cin >> n >> e;
    int dis[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
    }

    // output
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    // onno ak ta node k maj khany rekhy shortest path ber kora
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // output
    cout << "Updated" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// const int INF = 105;
// // const long long INF = LLONG_MAX;

// // long long dist[MAXN][MAXN];

// void initialize(int n)
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             if (i == j)
//             {
//                 dist[i][j] = 0;
//             }
//             else
//             {
//                 dist[i][j] = INF;
//             }
//         }
//     }
// }

// void floydWarshall(int n)
// {
//     for (int k = 1; k <= n; ++k)
//     {
//         for (int i = 1; i <= n; ++i)
//         {
//             for (int j = 1; j <= n; ++j)
//             {
//                 if (dist[i][k] != INF && dist[k][j] != INF)
//                 {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     initialize(n);

//     for (int i = 0; i < e; ++i)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         dist[a][b] = min(dist[a][b], (long long)w);
//     }

//     floydWarshall(n);

//     int q;
//     cin >> q;

//     for (int i = 0; i < q; ++i)
//     {
//         int x, y;
//         cin >> x >> y;

//         if (dist[x][y] == INF)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << dist[x][y] << endl;
//         }
//     }

//     return 0;
// }
