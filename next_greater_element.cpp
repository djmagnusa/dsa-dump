#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            vector<int> result;
            int index = 0;
            int flag=0;

            for(int i=0;i<nums1.size();i++)
            {
                int key=nums1[i];
                vector<int>::iterator itr = find(nums2.begin(), nums2.end(), key);

                if(itr!=nums2.end())
                {
                    index = distance(nums2.begin(), itr);
                }

                for(int j=index;j<nums2.size();j++)
                {
                    if(nums1[i] == nums2[j])
                    {
                        flag=1;
                    }

                    if(nums1[i] < nums2[j])
                    {
                        result.push_back(nums2[j]);
                        flag=0;
                        break;
                    }
                }
            }

            if(flag == 1)
            {
                result.push_back(-1);
                flag=0;
            }

            return result;
        }
};