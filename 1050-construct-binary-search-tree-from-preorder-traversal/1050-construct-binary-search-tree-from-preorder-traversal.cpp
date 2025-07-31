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
    TreeNode* build(vector<int>& p,int &i ,int b){
        if(i==p.size()|| p[i]>b) return NULL;
        TreeNode* node=new TreeNode(p[i++]);
        
        
        node->left=build(p,i,node->val);
        node->right=build(p,i,b);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        int i=0;
        return build(p,i,INT_MAX);
    }
};