#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> v[N];

void dfs(int src)
{
    visited[src] = true;
    cout << src << endl;
    for (int i = 0; i < v[src].size(); i++)
    {
        int child = v[src][i];
        if (visited[child] == false)
        {
            dfs(child);
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
    dfs(1);
    return 0;
}