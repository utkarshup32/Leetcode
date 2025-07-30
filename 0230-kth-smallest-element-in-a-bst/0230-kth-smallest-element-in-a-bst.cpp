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

    void inorder(TreeNode* root,vector<int> &path){
           if(root == nullptr){
            return ;
             }

        inorder(root->left,path);
        path.push_back(root->val);
        inorder(root->right,path);


    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> path;

        inorder(root,path);
         
        for(int i = 0; i< path.size(); i++){
            if(i == k-1){
                return path[i];
                
            }
        }

         

        return -1;

        
    }
};