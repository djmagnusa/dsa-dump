#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

        int coinChange(vector<int>& coins, int amount) 
        {
            int dp[amount+1];

            fill(dp, dp+amount+1, amount+1);

            dp[0] = 0;

            for(int i=0;i<=amount;i++)
            {
                for(int j=0;j<coins.size();j++)
                {
                    if(coins[j]<=i)
                    {
                        dp[i] = min(dp[i], 1+dp[i-coins[j]]);

                    }
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
        }
};