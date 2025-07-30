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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr=root;
        TreeNode* curr1=root;
        TreeNode* t=new TreeNode(val);
        while(curr){
            curr1=curr;
            if(curr->val<val){
                curr=curr->right;
            }else curr=curr->left;
            
        }if(curr1->val>val){
            curr1->left=t;
        }else curr1->right=t;
        return root;
    }
};