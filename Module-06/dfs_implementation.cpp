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

void dfs(int u)
{
    // section 1
    // actions just after entering the node
    visited[u] = true;
    cout << "Visiting Node: " << u << endl;

    for (int v : adj[u])
    {
        // section 2
        // actions before entering a new neighbor
        if (visited[v] == true)
            continue;
        dfs(v);
        // section 3
        // actions after exiting a neighbour
    }
    // section 4
    // actions before exiting a node
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
        // adj[u].push_back({v, w}); // directed, unweighted
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": ";
    //     for (auto j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    dfs(1);
    cout << "Visiting Array\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "Node " << i << " status:" << visited[i] << endl;
    }

    return 0;
}