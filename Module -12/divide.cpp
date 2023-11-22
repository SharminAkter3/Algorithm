#include <bits/stdc++.h>
using namespace std;

void divied(int a[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    if (l < r)
    {
        int mid = (l + r) / 2;
        divied(a, l, mid); // ordek ordek kory recursion chalabo
        divied(a, mid + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    divied(a, 0, n - 1); // a= array , 0= first position, n-1= last position

    return 0;
}