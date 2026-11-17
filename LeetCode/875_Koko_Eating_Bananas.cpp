class Solution {
    int64_t solve(int k, const vector<int> &piles) {
        int64_t result = 0;
        for(const int &pile: piles) {
            result += (pile+k-1)/k;
        }
        return result;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = (*max_element(piles.begin(), piles.end())); // (]
        while(r-l > 1) {
            int mid = (r - l) / 2 + l;
            if(solve(mid, piles) <= h) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
