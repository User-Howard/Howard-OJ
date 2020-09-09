class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """
    def fibonacci(self, n):
        arr = [0, 1]
        while len(arr)<n:
            arr.append(arr[-1] + arr[-2])
        return arr[n-1]