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
    int max=0;
public:
    int func(TreeNode* root){
        if(!root->left&&!root->right){
            return 1;
        }
        int dl=0;
        int dr=0;
        if(root->left){
            dl=func(root->left);
        }
        if(root->right){
            dr=func(root->right);
        }
        if(max<dl+dr)max=dl+dr;
        if(dl<dr)return dr+1;
        else return dl+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int i=func(root);
        return max;
    }
};


//solution 2
class Solution {
public:
    int maxDiameter(TreeNode* root, int& ans){
        if(root == nullptr) return 0;
        int left = maxDiameter(root->left, ans);
        int right = maxDiameter(root->right, ans);
        ans = max(left+right+1, ans);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        maxDiameter(root,ans);
        return ans-1;
    }
};