#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
bool visited[N];
vector<int> v[N];
int par[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    par[src] = -1;
    visited[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (!visited[child])
            {
                q.push(child);
                par[child] = parent;
                dis[child] = dis[parent] + 1;
                visited[child] = true;
            }
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    // for (int i = 1; i <= node; i++)
    // {
    //     cout << "Node " << i << " : " << par[i] << endl;
    // }
    int des;
    cin >> des;
    if (visited[des])
    {
        vector<int> path;
        int x = des;
        while (x != -1)
        {
            // cout << x << endl;
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Path Not Found" << endl;
    }

    return 0;
}