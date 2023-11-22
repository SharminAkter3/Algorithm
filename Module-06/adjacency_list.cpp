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
vector<pair<int, int>> adj[N]; // weighted

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
        // adj[u].push_back(v); //directed
        adj[u].push_back({v, w}); // directed, unweighted
        // adj[v].push_back(u); // undirected
    }

    // output
    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for (auto j : adj[i])
        {
            cout << "{" << j.first << ", " << j.second << "},";
        }
        cout << endl;
    }

    return 0;
}