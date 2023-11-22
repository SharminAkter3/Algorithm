#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        // pop a node from the queue and insert
        // unvisited neighbors of that node
        int u = q.front();
        q.pop();
        cout << "Visiting Node: " << u << endl;
        // section 1 : A node is being processed

        for (int v : adj[u])
        {
            // section 2: child processing
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            // section 3: child processing
            level[v] = level[u] + 1;
        }
        // section 4: same as section 1
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Level of " << i << ": " << level[i] << endl;
    }

    // int q;
    // cin >> q;
    // for (int i = 1; i <= q; i++)
    // {
    //     int s, d;
    //     cin >> s >> d;
    //     for (int i = 0; i < N; i++)
    //     {
    //         visited[i] = false;
    //         level[i] = -1;
    //     }

    //     cout << level[d] << endl;
    // }
    return 0;
}