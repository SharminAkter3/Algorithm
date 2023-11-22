#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int level[N];
vector<pair<int, int>> v[N];
bool visited[N];

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    level[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (visited[parentNode])
        {
            continue;
        }
        visited[parentNode] = true;
        int parentCost = parent.first;
        for (int i = 0; i < v[parentNode].size(); i++)
        {
            pair<int, int> child = v[parentNode][i];
            int childNode = child.first;
            int childCost = child.second;
            // path relaxation
            if (parentCost + childCost < level[childNode])
            {
                level[childNode] = parentCost + childCost;
                pq.push({level[childNode], childNode});
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