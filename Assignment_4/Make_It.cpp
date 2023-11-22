#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int calculate(int current, int n)
{
    if (current == n)
        return 1;
    if (current > n)
        return 0;

    if (dp[current] != -1)
        return dp[current];
    else
        return dp[current] = calculate(current + 3, n) || calculate(current * 2, n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }

        if (calculate(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
