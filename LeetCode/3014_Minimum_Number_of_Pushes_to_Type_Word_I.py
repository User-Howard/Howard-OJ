class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        result = 0
        for i in range(n):
            result += (i//8) + 1
        return result
