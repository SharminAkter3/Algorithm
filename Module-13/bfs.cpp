#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // 10 to the power 5
int level[N];          // disance er jnn ak ta array nibo
bool visited[N];
vector<int> v[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (visited[child] == false)
            {
                q.push(child);
                level[child] = level[parent] + 1;
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
    for (int i = 1; i <= node; i++)
    {
        cout << "Node " << i << " : " << level[i] << endl;
    }

    return 0;
}