#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool solve(int src, vector<int> &vis, vector<int> &order, vector<int> adj[])
        {
            vis[src] = 1;
            order[src] = 1;

            for(auto x : adj[src])
            {
                if(!vis[x])
                {
                    bool conf = solve(x, vis, order, adj);

                    if(conf == true)
                    {
                        return true;
                    }

                }

                else if(order[x])
                {
                    return true;
                }
            }

            order[src] = 0;
            return false;

        }

       bool isCyclic(int v, vector<int>, vector<int> adj[])
       {
           vector<int> vis(v,0);
           vector<int> order(v, 0);

           for(int i=0;i<v;i++)
           {
               if(!vis[i])
               {
                   bool c = solve(i, vis, order, adj);

                   if(c==true)
                   {
                       return true;
                   }
               }

           }

           return false;
       } 
};