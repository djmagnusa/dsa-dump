#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public: 
        vector<int> inorderTraversal(TreeNode *root) {
            stack<TreeNode*> stack; 
            vector<int> result;

            TreeNode* temp = root;

            while(temp || !stack.empty())
            {
                if(temp)
                {
                    stack.push(temp);
                    temp=temp->left;
                }

                else
                {
                    temp = stack.top();
                    stack.pop();
                    result.push_back(temp->val);
                    temp=temp->right;
                }
            }

            return result;
        }
};