class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        odds = [i for i in nums1 if i%2]
        evens = [i for i in nums1 if i%2==0]

        if not odds or not evens:
            return True
        return min(evens) - min(odds) >= 1

