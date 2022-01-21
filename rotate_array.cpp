#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int j=0;

        while(j<k)
        {
            int temp = nums[n-1];
            int i = n-1;

            while(i>0)
            {
                nums[i] = nums[i-1];
                i--;
            }

            nums[0] = temp;
            j++;
        }
    }
};