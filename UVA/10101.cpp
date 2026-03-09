#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

const array<pair<int, string>, 5> ctext = {
    make_pair(10000000, "kuti"),
    make_pair(100000, "lakh"),
    make_pair(1000, "hajar"),
    make_pair(100, "shata"),
    make_pair(1, "")
};
string solve(uint64_t n) {
    if(n==0) return "";
    else if(n<100) return to_string(n);

    string result = "";
    for(auto [num, pattern]: ctext) {
        if(n<num) continue;
        result += solve(n/num);
        if(not pattern.empty())
            result += ' ' + pattern;
        string recursive = solve(n%num);
        if(not recursive.empty())
            result += ' ' + recursive;
        break;
    }
    return result;
}
int main() {
    uint64_t N;
    while(cin >> N) {
        static int kase = 1;
        string kase_str = to_string(kase++);

        cout << string(4-kase_str.size(), ' ') << kase_str <<". ";
        if(N==0) {
            cout << "0\n";
            continue;
        }
        cout << solve(N) << '\n';
    }
    return 0;
}
