class Solution:
    """
    @param n: The number of digits
    @return: All narcissistic numbers with n digits
    """
    def getNarcissisticNumbers(self, n):
        def judge(a, L):
            RET = 0
            for i in str(a):
                RET += int(i)**L
            return RET
            
        ans = []
        for i in range(10**(n-1), 10**n):
            if judge(i, n) == i:
                ans.append(i)
        return ans if(n!=1) else ([0]+ans)