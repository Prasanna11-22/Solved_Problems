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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *temp=head;
        ListNode *prev=nullptr;
        bool chk=true;
         while(temp&&temp->next)
       {
        
        if(temp->val==temp->next->val)
        {
            chk=false;

            ListNode* p=temp;
            int dupl=temp->val;
            while((p)&&p->val==dupl)
            {
                p=p->next;
            }

            if(!prev)
            {
                head=p;
            }
            else
            {
            prev->next=p;
            }
            temp=p;
        }
        else
        {
             prev=temp;
             temp=temp->next;
        }
       }

        if(chk) return head;
       return (head!=nullptr&&!chk)?head:nullptr;
        
    }
};