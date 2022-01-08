#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int> &nums)
        {
            int sum=0;
            int max_sum = INT_MIN;

            for(auto n : nums)
            {
                sum = sum + n;
                max_sum = max(sum, max_sum);

                if(sum<0)
                {
                    sum=0;
                }
            }

            return max_sum;            
        }
};