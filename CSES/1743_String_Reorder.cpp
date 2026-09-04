#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

vector<int> letters(26, 0);
bool feasible(int remains, int prv) {
    int mx = *ranges::max_element(letters);
    if(mx > (remains+1)/2) return false;
    if(letters[prv] > remains/2) return false;
    return true;
}
int main() {
    string S;
    cin >> S;
    for(char c: S) letters[c-'A']++;
    int remains = accumulate(letters.begin(), letters.end(), 0);

    string answer;
    while(remains) {
        bool valid = false;
        for(int i=0;i<26;++i) {
            if(not letters[i]) continue;
            if(answer.size() and answer.back()==i+'A') continue;
            letters[i]--;
            remains--;
            if(feasible(remains, i)) {
                answer.push_back(i+'A');
                valid = true;
                break;
            }
            letters[i]++;
            remains++;
        }
        if(not valid) {
            break;
        }
    }
    if(remains) cout << "-1\n";
    else cout << answer << '\n';
    return 0;
}
