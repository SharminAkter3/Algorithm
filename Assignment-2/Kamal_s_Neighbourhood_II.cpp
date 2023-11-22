#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
vector<int> adj[N];
bool visited[N];
int val;
void bfs(int s)
{

    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            val++;
        }
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
    }
    int k;
    cin >> k;
    bfs(k);
    cout << val;

    return 0;
}