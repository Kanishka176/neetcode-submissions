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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> info(2);
        info[0]=k;
        dfs(root, info);
        return info[1];
    }

    void dfs(TreeNode* node, vector<int>& info){
        if(!node) return;

        dfs(node->left, info);
        if(info[0]==0) return;

        info[0]--;

        if(info[0]==0){
            info[1]= node->val;
            return;
        }

        dfs(node->right, info);
    }
};
