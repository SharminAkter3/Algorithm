#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;

class Edge
{
public:
    long long int u, v;
    long long int w;
    Edge(long long int u, long long int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<Edge> edgeList;

    while (m--)
    {
        long long int u, v;
        long long int w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        edgeList.push_back(ed);
    }
    long long int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    int s;
    cin >> s;
    dist[s] = 0;

    for (int k = 1; k <= n - 1; k++)
    {
        for (int i = 0; i < edgeList.size(); i++)
        {
            Edge ed = edgeList[i];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool cycle = false;

    for (int i = 0; i < edgeList.size(); i++)
    {
        Edge ed = edgeList[i];
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;
        if (dist[u] != INF && dist[v] > dist[u] + w)
        {
            cycle = true;
            break;
        }
    }

    int t, d;
    cin >> t;
    while (t--)
    {
        cin >> d;

        if (cycle)
        {
            cycle = true;
            break;
        }
        else
        {
            if (dist[d] >= INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {

                cout << dist[d] << endl;
            }
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }

    return 0;
}