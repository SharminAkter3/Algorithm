#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
int dis[N];
vector<int> v[N];
vector<int> cmp;

void dfs(int src)
{
    visited[src] = true;
    cmp.push_back(src);
    for (int child : v[src])
    {
        if (!visited[child])
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
    int cunt = 0;
    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            cunt++;
            dfs(i);
            for (int val : cmp)
            {
                cout << val << " ";
            }
            cout << endl;
            cmp.clear(); // ager component golo delete kory dithy hoby
        }
    }
    cout << cunt << endl;
    return 0;
}