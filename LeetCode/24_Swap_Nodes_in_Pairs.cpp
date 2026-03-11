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
    void swapNextTwo(ListNode* curr) {
        ListNode* a = curr->next;
        ListNode* b = a->next;
        ListNode* c = b->next;

        curr->next = b;
        b->next = a;
        a->next = c;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* dum = new ListNode(0, head);
        ListNode* fast = dum;
        for(int i=0;i<2;++i) {
            if(not fast->next) {
                return head;
            }
            fast = fast->next;
        }
        ListNode* slow = dum;
        int cnt = 0;
        while(fast) {
            fast = fast->next;
            if(cnt++%2==0)
                swapNextTwo(slow);
            slow = slow->next;
        }
        return dum->next;        
    }
};

