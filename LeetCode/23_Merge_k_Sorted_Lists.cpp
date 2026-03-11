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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* update_next(ListNode* curr, ListNode* x) {
        return curr->next = x;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int N = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i=0;i<N;++i) {
            if(lists[i] == nullptr) continue;
            pq.emplace(lists[i]);
        }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(not pq.empty()) {
            auto tmp = pq.top(); pq.pop();
            curr = update_next(curr, tmp);
            if(tmp->next) pq.emplace(tmp->next);
        }
        return dummy.next;
    }
};
