#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int dp[1001][1001];


        int solve(int N, int arr[], int s)
        {
            if(N==-1)
            {
                if(s==0)
                {
                    return 1;
                }

                return 0; 
            }

            if(s<0)
            {
                return 0;
            }

            if(s==0)
            {
                return 1; 
            }

            if(dp[N][s]!=-1)
            {
                return dp[N][s];
            }

            return dp[N][s] = solve(N-1,arr,s-arr[N]) || solve(N-1,arr,s);
        }

        int equalPartition(int N, int arr[])
        {
            int s=0;

            for(int i=0;i<N;i++)
            {
                s+=arr[i];
            }

            if(s&1)
            {
                return 0;
            }

            s=s/2;
            dp[N][s];
            memset(dp,-1,sizeof(dp));
            return solve(N-1,arr,s);
        }
};