#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;

    // akta array of vector banabo ... mani array banabo .j tar data type dity hoby vector
    vector<int> adjArray[node - 1];

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adjArray[a].push_back(b);
        adjArray[b].push_back(a);
    }

    for (int i = 0; i <= node; i++)
    {
        cout << "Index " << i << ":";
        for (int j = 0; j < adjArray[i].size(); j++)
        {
            cout << adjArray[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}