class Solution:
    def smallestPalindrome(self, s: str) -> str:
        counter = Counter(s)
        preLetters= ""
        midLetters = ""
        for key, num in sorted(counter.items()):
            if num%2:
                midLetters = key
            preLetters += key * (num // 2)
        return preLetters + midLetters + preLetters[::-1]
