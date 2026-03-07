class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> S(numRows, "");
        int counter = 0;
        bool asc = false;
        for(char& c: s) {
            S[counter] += c;

            if(counter==0) {
                asc = true;
            }
            if(counter==numRows-1) {
                asc = false;
            }
            if(asc) {
                counter++;
            } else {
                counter--;
            }
        }
        string result="";
        for(auto& ps: S) {
            result += ps;
        }
        return result;

    }
};
