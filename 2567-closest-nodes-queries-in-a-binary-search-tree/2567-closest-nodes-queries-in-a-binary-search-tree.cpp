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
    void inorder(TreeNode* root, vector<int> &ans){

       if(root == NULL){
        return;
       }   

       inorder(root->left, ans);
       ans.push_back(root->val);
       inorder(root->right, ans);

    }

    vector<int> findMinMax(vector<int> &in, int num){
         
        int s = 0;
        int e = in.size()-1;

        int mini = INT_MIN;
        int maxi = INT_MAX;

        while(s <= e){

            int mid = s + (e-s)/2;

            if(in[mid] == num){
                mini = num;
                maxi = num;
                break;
            }  

            else if(in[mid] < num){
                 mini = max(mini, in[mid]);
                 s = mid+1;
            }

            else{
                maxi = min(maxi, in[mid]);
                e = mid-1;
            }

        } 
        
        if(mini == INT_MIN){
            mini = -1;
        }

        if(maxi == INT_MAX){
            maxi = -1;
        }

        return {mini, maxi};

    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        vector<int> in;
        inorder(root, in);

        vector<vector<int>> ans;

        for(auto num : queries){

           ans.push_back(findMinMax(in, num));                         

        }   

        return ans;

    }
};