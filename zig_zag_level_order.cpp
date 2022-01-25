#include<bits/stdc++.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;

        if(!root)
        {
            return ans;
        }

        q.push(root);
        int toggle=1;

        while(!q.empty())
        {
            vector<int> temp;
            int sz = q.size();

            while(sz--)
            {
                TreeNode* t = q.front();
                temp.push_back(t->val);

                q.pop();

                if(t->left)
                {
                    q.push(t->left);
                }

                if(t->right)
                {
                    q.push(t->right);
                }
            }

            if(toggle%2==0)
            {
                reverse(temp.begin(), temp.end());
            }

            ans.push_back(temp);
            toggle=!toggle; 
        }
        return ans;
    }
};