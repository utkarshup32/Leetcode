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
        if(root==nullptr){
            root=new TreeNode(val);
        }
        else{

            TreeNode* newNode=new TreeNode(val);
            
            TreeNode* prevNode=root; 
            TreeNode* currNode=root;

            while(currNode!=nullptr){
                 prevNode=currNode;

                if(currNode->val>val){
                   
                    currNode=currNode->left;
                }
                else {
                 
                    currNode=currNode->right;

                }
            }
             if(prevNode->val>val){
            prevNode->left=newNode;
        }
        else{
            prevNode->right=newNode;
        }

        }

       

        return root;
    }
};