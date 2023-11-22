#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    int adj[node + 1][node + 1]; // [row][col] = node+1 ..node joto ta hoby toto theky 1 beshi

    // suru ty e sob golo node er value 0 define kory dibo
    for (int i = 0; i <= node; i++)
    {
        for (int j = 0; j <= node; j++)
        {
            adj[i][j] = 0;
            if (i == j)
                adj[i][j] = 1;
        }
    }
    while (edge--)
    {
        int row, col;
        cin >> row >> col;
        // connected edge golo r man 1 kory dithy hoby
        adj[row][col] = 1;
        adj[col][row] = 1; // undirected graph tai 2 tai 1 kory dithy hoby
    }

    for (int i = 0; i <= node; i++)
    {
        for (int j = 0; j <= node; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}