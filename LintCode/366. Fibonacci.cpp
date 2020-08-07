// Your submission beats 66.80% Submissions!
#include <iostream>
using namespace std;

class Solution
{
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n)
    {
        int fib[n];
        fib[0] = 0, fib[1] = 1;
        for (int i = 2; i < n; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n - 1];
    }
};