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
    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr){
            return 1;
        }
        int a=0;
        int b=0;
        if(root->left!=nullptr){
            a=1+minDepth(root->left);
        }
        if(root->right!=nullptr){
            b=1+minDepth(root->right);
        }
        if(a==0){
            return b;
        }else if(b==0){
            return a;
        }
        return min(a,b);
    }
};