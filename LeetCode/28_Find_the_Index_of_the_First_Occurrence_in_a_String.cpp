class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N = haystack.size();
        const int M = needle.size();
        for(int i=0;i<N-M+1;++i) {
            bool flag = true;
            for(int j=0;j<M;++j) {
                if(haystack[i+j]!=needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return i;
            }
        }
        return -1;
    }
};

