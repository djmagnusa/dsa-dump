#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    int maxSumIs(int arr[], int n)
    {
        int dp[n];

        for(int i=0;i<n;i++)
        {
            dp[i] = arr[i];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }

        int ma = 0;

        for(int i=0;i<n;i++)
        {
            ma = max(ma, dp[i]);
        }

        return ma;
    }
};