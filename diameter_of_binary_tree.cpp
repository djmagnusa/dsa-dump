#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution
{
    public:
        int maximum;

        int func(Node* root)
        {
            if(!root)
            {
                return 0;
            }

            int x = func(root->left);
            int y = func(root->right);
            maximum = max(maximum, x+y+1);
            return (max(x,y)+1);
        }

        int diameter(Node* root)
        {
            maximum = INT_MIN;
            int x = func(root);
            return maximum;
        }
};