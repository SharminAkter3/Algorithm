#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int leftSize = m - l + 1;      // protom part tar size ber korbo
    int rightSize = r - m;         // last part tar size ber korbo
    int L[leftSize], R[rightSize]; // new dui ta array ty copy kory rakhbo
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i]; // left size theky mid porjonto jabo ..value golo new array ty store korbo
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }

    // output check
    // for (int i = 0; i < rightSize; i++)
    // {
    //     cout << R[i] << " ";
    // }

    int i = 0, j = 0, cur = l;
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            a[cur] = L[i];
            i++;
        }
        else
        {
            a[cur] = R[j];
            j++;
        }
        cur++;
    }
    while (i < leftSize)
    {
        a[cur] = L[i];
        i++;
        cur++;
    }
    while (j < rightSize)
    {
        a[cur] = R[j];
        j++;
        cur++;
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
    merge(a, 0, 3, n - 1); // a= array, 0= 0 theky suru hoby protom part ta , 3= 3 ty shes hoby , n-1= shes er part ta n-1 porjonto cholby

    // output
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}