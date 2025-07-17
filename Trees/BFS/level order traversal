class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root==NULL) return a;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>ans;
            for(int i=0;i<s;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                ans.push_back(n->val);
            }a.push_back(ans);

        }return a;
    }
};