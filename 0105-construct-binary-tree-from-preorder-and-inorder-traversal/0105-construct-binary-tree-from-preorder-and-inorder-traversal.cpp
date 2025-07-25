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
/**class Solution {
public:
TreeNode* constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (preStart > preEnd || inStart > inEnd) return NULL;

  TreeNode* root = new TreeNode(preorder[preStart]);
  int elem = mp[root -> val];
  int nElem = elem - inStart;

  root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
  int preStart = 0, preEnd = preorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
};*/
class Solution {
public:

    TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
        map<int,int> mp;
        for(int i=0; i<=inorder.size()-1; i++){
            mp[inorder[i]]=i;
        }TreeNode* root=consTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);       
        return root;
    }
    TreeNode* consTree(vector < int > & preorder,int prestart,int preend, vector < int > & inorder,int instart,int inend, map<int,int> &mp) {
        if (prestart > preend || instart > inend) return NULL;
        TreeNode* root= new  TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        int inlength=inroot-instart;
        root->left=consTree(preorder,prestart+1,prestart+inlength,inorder,instart,inroot-1,mp);
        root->right=consTree(preorder,prestart+inlength+1,preend,inorder,inroot+1,inend,mp);
        return root;
    }
};