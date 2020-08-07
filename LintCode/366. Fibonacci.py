# Your submission beats 96.60% Submissions!
class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """
    def fibonacci(self, n):
        fib = [0, 1]
        while len(fib)<n:
            fib.append(fib[-1]+fib[-2])
        return fib[n-1]
