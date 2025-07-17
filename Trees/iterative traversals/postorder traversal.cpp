class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int >ans;
        if(!root) return ans;
        stack<TreeNode*>s,s1;
        s.push(root);
        while(!s.empty()){
            TreeNode*  r=s.top();
            s.pop();
            s1.push(r);
            if(r->left) s.push(r->left);
            if(r->right) s.push(r->right);
            
        }while(!s1.empty()){
            ans.push_back(s1.top()->val);
            s1.pop();
        }return ans;
    }
};