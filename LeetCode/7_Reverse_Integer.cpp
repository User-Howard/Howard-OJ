class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int int_max = (1LL<<31)-1;
        bool neg = false;
        if(x<0) {
            neg = true;
            if(x==-int_max-1) return 0;
            x *= -1;
        }
        while(x) {
            if(result + 0.1*(x%10)>=1.0*int_max/10) {
                return 0;
            }
            result = 10*result + (x%10);
            x /= 10;
        }
        if(neg) result *= -1;
        return result;
    }
};
