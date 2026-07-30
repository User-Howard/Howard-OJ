class Solution {
public:
bool bad=false;
    int permutation_count(map<int, int> cnt) {
        int64_t result = 1;
        int total = 0;
        for(int i='a';i<='z';++i) {
            for(int j=1;j<=cnt[i];++j) {
                ++total;
                result = (result * total) / j;
                if(result > 1e7) return 1e7;
            }
        }
        return result;
    }
    optional<string> kth_permutation(int k, string elements) {
        int n = elements.size();
        map<int,int> cnt;
        for (char x : elements) cnt[x]++;
        string result = "";
        string lst;
        for(int i=0;i<n;++i) {
            for(char j='a';j<='z';++j) {
                if(not cnt[j]) continue;
                --cnt[j];
                int pc = permutation_count(cnt);
                if(k<=pc) {
                    result += j;
                    break;
                }
                k -= pc;
                ++cnt[j];
            }
            if(lst==result) return nullopt;
            lst = result;
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
        string half_letters = "";
        string mid_letter = "";
        map<char, int> cnt;
        for(char c: s) {
            cnt[c]++;
        }
        for(auto [c, num]: cnt) {
            if(num%2) mid_letter += c;
            half_letters += string(num/2, c);
        }
        optional<string> kth_perm = kth_permutation(k, half_letters);
        if(not kth_perm.has_value()) return "";

        string left_half = kth_perm.value();
        string right_half(left_half.rbegin(), left_half.rend());
        return left_half + mid_letter + right_half;
        }
};
