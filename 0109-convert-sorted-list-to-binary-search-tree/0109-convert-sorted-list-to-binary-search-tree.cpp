/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL; 
        if(!head->next) return new TreeNode(head->val);
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* slow1;
        while(fast && fast->next){
            slow1=slow;
            fast=fast->next;
            if(fast->next){
                fast=fast->next;   
            } slow=slow->next;
        }TreeNode* node=new TreeNode(slow->val);
        slow1->next=NULL;
        node->left=sortedListToBST(head);
        node->right=sortedListToBST(slow->next);
        return node;
    }
};