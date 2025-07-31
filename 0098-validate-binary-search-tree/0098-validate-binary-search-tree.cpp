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
    bool bst(TreeNode* root, long long n,long long x){
        if(!root) return true; 
        if(root->val>=x || root->val <=n) return false;
        return bst(root->left,n,root->val) && bst(root->right,root->val,x);
    }
    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN,LLONG_MAX);

    }
};