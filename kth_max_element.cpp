#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int findKthLargest(vector<int>& nums , int k)
        {
            sort(nums.begin(), nums.end());
            return nums[nums.size()-1 - (k-1)];
        }
};