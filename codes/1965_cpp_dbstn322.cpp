#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int box[1001];

int main()
{
    int n;
    cin >> n;

    int maximum = 0;

    for (int i = 0; i < n; i++)
        cin >> box[i];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (box[j] < box[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        if (maximum < dp[i])
            maximum = dp[i];
    }

    cout << maximum << endl;

    return 0;
}