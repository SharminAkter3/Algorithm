#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 1e3 + 5;
bool visited[N][N];
int dis[N][N];
int row, col;

vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int childI, int childJ)
{
    if (childI >= 0 && childI < row && childJ >= 0 && childJ < col)
        return true;
    else
        return false;
}

void bfs(int srcI, int srcJ)
{
    queue<pii> q;
    q.push({srcI, srcJ});
    dis[srcI][srcJ] = 0;
    visited[srcI][srcJ] = true;
    while (!q.empty())
    {
        pii parent = q.front();
        int parI = parent.first;
        int parJ = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pii p = path[i];
            int childI = parI + p.first;
            int childJ = parJ + p.second;
            // cout << childI << " " << childJ << endl;
            if (isValid(childI, childJ) && (visited[childI, childJ]))
            {
                visited[childI][childJ] = true;
                q.push({childI, childJ});
                dis[childI][childJ] = dis[parI][parJ] + 1;
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    char a[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    int srcI, srcJ;
    cin >> srcI >> srcJ;
    bfs(srcI, srcJ);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}