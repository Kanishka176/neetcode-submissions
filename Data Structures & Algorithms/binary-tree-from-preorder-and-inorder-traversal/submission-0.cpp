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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        unordered_map<int,int> mp;

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }

        TreeNode* root= constructTree(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1, mp);

        return root;
    }

    TreeNode* constructTree(vector<int>& preorder, int preLow, int preHigh, vector<int>& inorder, int inLow, int inHigh, unordered_map<int,int>& mp){
        if(preLow>preHigh || inLow>inHigh) return nullptr;

        TreeNode* node= new TreeNode(preorder[preLow]);
        int curRoot= mp[node->val];
        int leftEl= curRoot-inLow;

        node->left= constructTree(preorder, preLow+1, leftEl+preLow, inorder, inLow, curRoot-1, mp );
        node->right= constructTree(preorder, leftEl+preLow+1, preHigh, inorder, curRoot+1, inHigh, mp);

        return node;
    }
};
