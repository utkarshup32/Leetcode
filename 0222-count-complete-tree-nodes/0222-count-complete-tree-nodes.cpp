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
    int findl(TreeNode* root){
        int k=0;
        while(root){
            k++;
            root=root->left;
        }return k;
    }int findr(TreeNode* root){
        int k=0;
        while(root){
            k++;
            root=root->right;
        }return k;
    }
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int lh=findl(root);
        int rh=findr(root);
        if(lh==rh) return (1<<lh) -1 ;
        return 1+ countNodes(root->left) +countNodes(root->right);
    }
};