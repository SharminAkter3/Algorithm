// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;
// const int N = 1e5 + 7;
// const int INF = 1e9 + 7;
// vector<pii> g[N];
// vector<pair<pii, int>> list_of_edges;
// int d[N]; // distance vector
// int n, m;

// void bellman_ford(int s)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         // all edges weight was infinity
//         d[i] = INF;
//     }
//     d[s] = 0; // source 0 is definited

//     // graph diye korly tkn
//     // for (int i = 1; i < n; i++)
//     // {
//     //     // all edges relaxation
//     //     for (int u = 1; u <= n; u++)
//     //     {
//     //         for (pii vpair : g[u])
//     //         {
//     //             int v = vpair.first;
//     //             int w = vpair.second;

//     //             if (d[u] != INF && d[v] > d[u] + w)
//     //             {
//     //                 d[v] = d[u] + w;
//     //             }
//     //         }
//     //     }
//     // }

//     // list of edges diye korly tkn
//     for (int i = 1; i < n; i++)
//     {
//         // all edges relaxation
//         for (auto edge : list_of_edges)
//         {
//             int u = edge.first.first;
//             int v = edge.first.second;
//             int w = edge.second;

//             if (d[u] != INF && d[v] > d[u] + w)
//             {
//                 d[v] = d[u] + w;
//             }
//         }
//     }
// }

// // complexity -> O(|E| |V|) / O(nm)

// int main()
// {
//     // graph input nicchi
//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});               // graph diye korly
//         list_of_edges.push_back({{u, v}, w}); // list of edges diye korly
//     }

//     bellman_ford(1); // source diye call korbo

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Distance of " << i << ": " << d[i] << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
int dist[N]; // distance vector
int n, m;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[s] = 0;

    for (int i = 1; i < n; i++)
    {
        // all adges relaxation
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if (dist[u] != INF && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    bellman_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "distance of " << i;
        cout << " : " << dist[i] << endl;
    }

    return 0;
}