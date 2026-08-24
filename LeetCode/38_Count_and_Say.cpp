class Solution {
public:
    string run_length_of(string s) {
        string output = "";
        char prv = s[0];
        int count = 1;
        for(int i=1;i<=size(s);++i) {
            if(i==size(s)) {
                output += to_string(count) + prv;
                break;
            }
            if(s[i] != prv) {
                output += to_string(count) + prv;
                prv = s[i];
                count = 1;
            } else {
                count++;
            }
        }
        return output;
    }
    string countAndSay(int n) {
        string base = "1";
        for(int i=1;i<n;++i) {
            base = run_length_of(base);
        }
        return base;
    }
};
