#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
int n, m;
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc)
        {
            int newi = i + d.first;
            int newj = j + d.second;

            if (isValid(newi, newj) && !visited[newi][newj])
            {
                q.push({newi, newj});
                visited[newi][newj] = true;
                level[newi][newj] = level[i][j] + 1;
            }
        }
    }
}

void reset_level_visit()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';
        // cout << "(" << si << "," << sj << ") ";
        // cout << "(" << di << "," << dj << ")" << endl;
        bfs(si, sj);
        cout << level[di][dj] << endl;
        reset_level_visit();
    }

    return 0;
}