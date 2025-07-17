/*
single stack postorder traversal is 
not very tough.
it is nearly same as preorder except at 

1....here the orderndi reverse of preorder

2....finally we reverse the ans array
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* current = stack.top();
            stack.pop();
            result.push_back(current->val);

            if (current->left) {                 // 1
                stack.push(current->left);
            }
            if (current->right) {
                stack.push(current->right);
            }
        }

        reverse(result.begin(), result.end());    //2
        return result;
    }
};