#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void printpath(map<pii,pii>mp, pii u)
{
    if(u.first==0 && u.second==0) //if both the jug in that state is 0 print 0 or 0
    {
        cout<<0<<" "<<0<<endl;
        return;
    }

    printpath(mp,mp[u]); //if both are not zero then map it to that particuar pair 
    cout<<u.first<<" "<<u.second<<endl;
}

void BFS(int a, int b, int target)
{
    map<pii, int> m;
    bool isSolvable=false;
    vector<tuple<int, int, int>>path;
    map<pii, pii> mp;

    queue<pii> q;

    q.push(make_pair(0,0));

    while(!q.empty())
    {
        auto u = q.front();

        q.pop();

        if(m[u] == 1)
        {
            continue;
        }

        if((u.first > a || u.second > b || u.first < 0 || u.second < 0))
        {
            continue;
        }

        m[{u.first, u.second}]=1;

        if(u.first==target || u.second==target)
        {
            isSolvable = true;

            printpath(mp,u);

            if(u.first == target)
            {
                if(u.second!=0)
                {
                    cout<<u.first<<" "<<0<<endl; //emptying jug2
                }
            }

            else
            {
                if (u.first != 0)
                {
                    cout<<0<<" "<<u.second<<endl; //emptying jug1 since target found in jug2
                }
            }

            return;
        }

        if(m[{u.first,b}] != 1) //state in which jug2 is full, if this state already not there push it to the queue
        {
            q.push({u.first,b});
            mp[{u.first,b}]=u;
        }

        if(m[{a,u.second}] != 1) //state in which jug1 is full, if this state already not there push it to the queue
        {
            q.push({a,u.second});
            mp[{a,u.second}]=u; //marking this pair with current pair
        }

        //trasfer from jug1 to jug2
        int d = b - u.second;

        if(u.first >= d)
        {
            int c = u.first - d;
            if(m[{c,b}]!=1)
            {
                q.push({c,b});
                mp[{c,b}]=u; 
            }
        }

        else
        {
            int c = u.first + u.second;
            if(m[{0,c}]!=1)
            {
                q.push({0,c});
                mp[{0,c}]=u;
            }
        }

        //transfer from jug2 to jug1

        d = a - u.first;
        if(u.second >= d)
        {
            int c = u.second - d;
            if(m[{a,c}]!=1)
            {
                q.push({a,c});
                mp[{a,c}]=u; 
            }
        }

        else
        {
            int c = u.first + u.second;
            if(m[{c,0}]!=1)
            {
                q.push({c,0});
                mp[{c,0}]=u;
            }
        }

        //empty jug2
        if(m[{u.first,0}]!=1)
        {
            q.push({u.first,0});
            mp[{u.first,0}]=u;
        }

        //empty jug1
        if(m[{0,u.second}]!=1)
        {
            q.push({0,u.second});
            mp[{0,u.second}]=u;
        }

    }

    if(!isSolvable)
    {
        cout<<"No solution";
    }

}

int main()
{
    int jug1, jug2, target;
    cout<<"Enter capacity of Jug 1: ";
    cin>>jug1;

    cout<<"Enter capacity of Jug 2: ";
    cin>>jug2;

    cout<<"Enter target amount of water: ";
    cin>>target;

    BFS(jug1, jug2, target);
    return 0;
}