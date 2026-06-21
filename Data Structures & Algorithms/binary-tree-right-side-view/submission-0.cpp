/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector< int> res;
        queue<TreeNode*> q;
        if (!root) return {};
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                auto* node = q.front(); q.pop();
                 if (i == 0) {
                    res.push_back(node->val);
                }

                if (node->right) {
                    q.push(node->right);
                }

                if (node->left) {
                    q.push(node->left);
                }
            }
        }

        return res;
    }
};
