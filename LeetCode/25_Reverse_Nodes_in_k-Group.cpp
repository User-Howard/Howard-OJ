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
    ListNode* swapK(ListNode* head, int k) {
        ListNode* cur = head->next;
        ListNode* nxt = cur->next;
        cur->next = nullptr;

        for(int i=1;i<k;++i) {
            auto tmp = nxt->next;
            nxt->next = cur;
            head->next = nxt;

            cur = nxt;
            nxt = tmp;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dum = new ListNode(0, head);
        ListNode* slow = dum;
        ListNode* fast = dum;
        bool flag = false;
        while(true) {
            for(int i=0;i<k;++i) {
                if(not fast->next) {
                    flag = true;
                    break;
                }
                fast = fast->next;
            }
            if(flag) break;
            auto tmp1 = slow->next;
            auto tmp2 = fast->next;
            swapK(slow, k);

            tmp1->next = tmp2;
            fast = slow = tmp1;
        }
        return dum->next;        
    }
};

