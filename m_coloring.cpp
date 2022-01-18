#include<bits/stdc++.h>
using namespace std;

bool safe_color(bool graph[101][101],  int V, int clr, int node, int color[])
{
    for(int i=0;i<V;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==clr)
        {
            return false;
        }
    }

    return true;
}

bool coloring(bool graph[101][101], int V, int m, int node, int color[])
{
    if(node==V)
    {
        return true;
    }

    for(int i=1;i<=m;i++)
    {
        if(safe_color(graph, V, i, node, color))
        {
            if(coloring(graph,V,m,node+1,color));
            {
                return true;
            }

            color[node]=0; //when backtracking
        }
    }

    return false;
    
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    memset(color, 0, sizeof(color));

    if(coloring(graph,V,m,0,color))
    {
        return true;
    }

    return false;
}