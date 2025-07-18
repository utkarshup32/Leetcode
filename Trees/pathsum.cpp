/*113. Path Sum II

Given the root of a binary tree and an integer targetSum,
 return all root-to-leaf paths where the sum of the node 
 values in the path equals targetSum. Each path should be 
 returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and 
ending at any leaf node. A leaf is a node with no children.
*/
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
    bool solve(TreeNode* root,vector<vector<int>>&ans,vector<int>&k,int sum, int targetSum){
        if(!root) return false;
        k.push_back(root->val);
        sum=sum+root->val;
        if(!root->left && !root->right) {
            if (sum==targetSum){
                ans.push_back(k);
                
            }
        }if(solve(root->left,ans,k,sum,targetSum) ) return true;
        if (solve(root->right,ans,k,sum,targetSum)) return true;
        k.pop_back();
        return false; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>>ans;
        vector<int>k;
        solve(root,ans,k,0,targetSum);
        return ans;
    }
};