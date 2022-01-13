#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[], int N, int K)
{
    int ma = 0;
    int mi = 0;
    int i = 0;
    int j = N-1;

    sort(candies, candies+N);

    while(i<=j)
    {
        mi += candies[i];
        i++;
        j=j-K;
    }

    reverse(candies, candies+N);

    i = 0;
    j = N-1;

    while(i<=j)
    {
        ma += candies[i];
        i++;
        j=j-K;
    }

    return { mi, ma};
}