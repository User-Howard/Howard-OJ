class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> pq;
            for(int i: stones) pq.push(i);
            while(pq.size()>=2) {
                int a = pq.top(); pq.pop();
                int b = pq.top(); pq.pop();
                if(a-b) pq.push(abs(a-b));
            }
            return pq.empty()? 0 : pq.top(); 
        }
    };