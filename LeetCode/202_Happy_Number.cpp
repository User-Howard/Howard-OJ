class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int> st;
            while(n!=1 and not st.count(n)) {
                st.insert(n);
                int nt = 0;
                while(n) {
                    nt += pow(n%10, 2);
                    n /= 10;
                }
                //cout << nt << '\n';
                n = nt;
            }
            return n==1;
        }
    };