#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxArea(vector<int> &height) 
        {
            int i=0, j=height.size()-1, temp=0, resultant=0;

            while(i<j)
            {
                if(height[i]<=height[j])
                {
                    resultant = height[i] * (j-i);
                    i++; 
                }

                else
                {
                    resultant = height[j] * (i-j);
                    j--;
                }

                if(resultant>temp)
                {
                    temp=resultant;
                }
            }
            
            return temp;
        }     
};