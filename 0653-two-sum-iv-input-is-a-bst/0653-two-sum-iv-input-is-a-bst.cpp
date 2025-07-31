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
    unordered_set<int> set;
public:
    bool help(TreeNode* root1, int k){
        
        if(!root1) return false;
        if(set.count(k-root1->val)) return true;
        set.insert(root1->val);
        return help(root1->left,k) || help(root1->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return help(root,k);
    }
};