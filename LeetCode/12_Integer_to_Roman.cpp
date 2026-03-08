class Solution {
public:
    map<int, string> mp = {
        {1, "I"},
            {4, "IV"},
        {5, "V"},
            {9, "IX"},
        {10, "X"},
            {40, "XL"},
        {50, "L"},
            {90, "XC"},
        {100, "C"},
            {400, "CD"},
        {500, "D"},
            {900, "CM"},
        {1000, "M"},
    };
    string intToRoman(int num) {
        string result = "";
        while(num) {
            auto target = prev(mp.upper_bound(num));
            int quotient = num / target->first;
            for(int i=0;i<quotient;++i)
                result += target->second;
            num %= target->first;
        }
        return result;
    }
};
