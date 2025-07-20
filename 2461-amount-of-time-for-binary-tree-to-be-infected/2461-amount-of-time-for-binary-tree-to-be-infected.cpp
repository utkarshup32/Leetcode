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
    int time( TreeNode * target,unordered_map<TreeNode *,TreeNode *> &mpp){
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(target);
        visited[target]=true;
        int maxi=0;
        while(!q.empty()){
            int fl=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    fl=1;
                    visited[node->left]=true;
                    q.push(node->left);
                }if(node->right && !visited[node->right]){
                    fl=1;
                    visited[node->right]=true;
                    q.push(node->right);
                }
                auto it = mpp.find(node);
                if(it != mpp.end() && it->second && !visited[it->second]) {
                    fl=1;
                    visited[mpp[node]]=true;
                    q.push(mpp[node]);
                }
            }if(fl) maxi++;
        }return maxi;
    }           
    TreeNode * bfs(TreeNode * root,unordered_map<TreeNode *,TreeNode *> &mpp,int start){
        queue<TreeNode *>q;
        q.push(root);
        TreeNode * k;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * node=q.front();
                q.pop();
                if(node->val==start){ 
                    k=node;
                }
                if(node->left){
                    mpp[node->left]=node;
                    q.push(node->left);
                }if(node->right){
                    mpp[node->right]=node;
                    q.push(node->right);
                }
            }   
        }return k;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *,TreeNode *>mpp;
        TreeNode * target=bfs(root,mpp,start);
        int maxi=time(target,mpp);
        return maxi;
    }
};