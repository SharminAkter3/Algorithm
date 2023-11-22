#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int level[N];
vector<pair<int, int>> v[N];

void dijkstra(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            pair<int, int> child = v[parent][i];
            int childNode = child.first;
            int childCost = child.second;
            // path relaxation
            if (level[parent] + childCost < level[childNode])
            {
                level[childNode] = level[parent] + childCost;
                q.push(childNode);
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
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w}); // cost soho nibo
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= node; i++)
    {
        level[i] = INT_MAX;
    }

    dijkstra(1);

    for (int i = 1; i <= node; i++)
    {
        cout << "Node " << i << " : " << level[i] << endl;
    }

    return 0;
}