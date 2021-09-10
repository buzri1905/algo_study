#include <iostream>

using namespace std;
int dp[1001];

int main()
{
    int n;
    cin >> n;

    int box[n];

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        box[i] = num;
    }

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (box[j] < box[i] && dp[j] >= dp[i])
                dp[i] = dp[j] + 1;
        }

        if (max < dp[i])
            max = dp[i];
    }

    cout << max << endl;

    return 0;
}