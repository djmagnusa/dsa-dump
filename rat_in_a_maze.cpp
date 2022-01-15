#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<string> v;

    void dfs(int i, int j, string s, vector<vector<int>> &m, int n, vector<vector<int>> &vis)
    {
        if(i<0 || j<0 || i>=n || j>=n)
        {
            return;
        }  

        if(m[i][j] == 0 || vis[i][j] == 1)
        {
            return;
        }

        dfs(i-1,j,s+'U',m,n,vis);
        dfs(i+1,j,s+'D',m,n,vis);
        dfs(i,j-1,s+'L',m,n,vis);
        dfs(i,j+1,s+'R',m,n,vis);

        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector <int>> &m, int n)
    {
        vector<vector<int>> vis(n, vector<int> (n));

        if(m[0][0] == 0)
        {
            return v;
        }

        if(m[n-1][n-1] == 0)
        {
            return v;
        }

        string s = "";
        dfs(0,0,s,m,n,vis);
        sort(v.begin(), v.end());

        return v;
    }
};