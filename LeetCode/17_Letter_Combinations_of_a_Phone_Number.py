from itertools import product
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mp = [None] * 10
        mp[2] = "abc"
        mp[3] = "def"
        mp[4] = "ghi"
        mp[5] = "jkl"
        mp[6] = "mno"
        mp[7] = "pqrs"
        mp[8] = "tuv"
        mp[9] = "wxyz"

        ans = list[str]()
        for a in product(*(mp[int(d)] for d in digits)):
            ans.append(''.join(a))
        return ans
