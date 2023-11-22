#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const long long INF = 1e18;
long long dis[N][N];

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], (long long)w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }

    return 0;
}
