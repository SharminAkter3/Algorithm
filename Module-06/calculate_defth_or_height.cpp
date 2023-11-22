#include <bits/stdc++.h>
using namespace std;
void init_code()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdin);
    // #endif // ONLINE_JUDGE
}

const int N = 1e6 + 5;
// vector<int> adj[N]; // unweighted
vector<int> adj[N]; // weighted

bool visited[N];

int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    cout << "Visiting Node: " << u << endl;

    for (int v : adj[u])
    {

        if (visited[v] == true)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        if (height[v] + 1 > height[u])
            height[u] = height[v] + 1;
    }
}

int main()
{
    init_code();

    int n, m; // n= number of nodes, m= number of edges
    cin >> n >> m;

    // input
    for (int i = 0; i < m; i++) // number of edges golo input nibo
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed
        adj[v].push_back(u); // undirected
    }

    dfs(1);
    cout << "Visiting Array\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "depth of Node " << i << ":" << depth[i] << endl;
    }

    return 0;
}