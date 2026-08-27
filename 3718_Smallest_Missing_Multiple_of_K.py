class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        li = set(filter(lambda x: x%k==0, nums+[0]))
        ps = set(range(k, max(li)+k+1, k))
        return min(ps-li)

