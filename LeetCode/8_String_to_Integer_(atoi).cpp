class Solution {
public:
    bool _str_lt(string a, string b) { // assert that both a and b are positive and not null
        if(a.length() != b.length()) {
            return a.length() < b.length();
        }
        if(a == b) return 0;
        return a.compare(b) < 0;
    }
    int _stoi(string s) {
        if(s.length() == 0) return 0;
        bool neg = false;
        int start_at = 0;
        if(s[0]=='-') {
            neg = true;
            start_at = 1;
        }
        if(s[0]=='+') {
            start_at = 1;
        }
        if(not neg and _str_lt("2147483647", s.substr(start_at))) {
            return 2147483647;
        }
        if(neg and _str_lt("2147483648", s.substr(start_at))) {
            return -2147483648;
        }
        return stoi(s);
    }
    string _remove_zero(string s) {
        if(s.length()==0) return "";
        string result = "";
        int ptr=0;
        if(s[0]=='-') {
            result += '-';
            ptr++;
        }
        while(ptr<s.length() and s[ptr]=='0') {
            ptr++;
        }
        if(ptr==s.length()) return "0";
        result += s.substr(ptr);
        return result;
    }
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        string result_str = "";
        int start_at = 0;
        int end_at = 0;
        while(start_at<s.length() and s[start_at]==' ') start_at++;
        end_at = start_at;
        if(s[start_at]=='-' or s[start_at]=='+') {
            end_at++;
        }
        if(not isdigit(s[end_at])) return 0;
        while(end_at<s.length() and isdigit(s[end_at])) {
            end_at++;
        }
        cout << _remove_zero(s.substr(start_at, end_at-start_at));
        return _stoi(_remove_zero(s.substr(start_at, end_at-start_at)));
    }
};
