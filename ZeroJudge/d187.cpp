#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int mp[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    string S;
    getline(cin, S);
    for (int kase = 1; kase <= T; ++kase) {
        int answer = 0;
        getline(cin, S);
        for (char i : S) {
            if (i == ' ')
                answer += 1;
            else if ('a' <= i and i <= 'z')
                answer += mp[i - 'a'];
        }
        cout << "Case #" << kase << ": " << answer << "\n";
    }
    return 0;
}