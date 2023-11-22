#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main()
{
    int e;
    cin >> e;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    while (!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
