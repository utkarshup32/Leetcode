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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum=0;
        int carry=0;

        ListNode dummy;
        ListNode* head=&dummy;

        while(l1 || l2)
        {
          sum=carry;
          carry=0;
          if(l1) 
          {sum+=l1->val;
          l1=l1->next;
          }
          if(l2) 
          {sum+=l2->val;
          l2=l2->next;
          }
          head->next=new ListNode(sum%10);
          head=head->next;
          carry=sum/10;
        }
        if(carry!=0){
            head->next=new ListNode(carry);
        }
        return dummy.next;
    }
};