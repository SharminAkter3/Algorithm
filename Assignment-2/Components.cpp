#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

int cnt = 0;
vector<int> v;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
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
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;
        cnt = 0;
        bfs(i);
        if (cnt > 1)
        {
            v.push_back(cnt);
        }
    }

    sort(v.begin(), v.end());

    for (int r : v)
    {
        cout << r << " ";
    }
    return 0;
}