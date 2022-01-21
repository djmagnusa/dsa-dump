#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
        {
            int mapSize;
            vector<int> result;
            
            int maxElementA = *max_element(nums1.begin(), nums1.end());
            int maxElementB = *max_element(nums2.begin(), nums2.end());

            if(maxElementA > maxElementB)
            {
                mapSize = maxElementA;
            }

            else
            {
                mapSize = maxElementB;
            }

            int *A = new int[mapSize+1];

            for(int i=0;i<mapSize+1;i++)
            {
                A[i] = 0;
            }
                      
            for(int i=0;i<nums1.size();i++)
            {
                if(A[nums1[i]] == 0)
                {
                    for(int j=0;j<nums2.size();j++)
                    {
                        if(nums1[i] == nums2[j])
                        {
                            result.push_back(nums1[i]);
                            A[nums1[i]] = 1;
                            break;
                        }
                    }
                }
            }
            
            return result;

        }

};