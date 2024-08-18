#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
vector<vector<int> > answers;
void solve(vector<int> &vec, int rest, int minValue=2) {
    if(rest == 1) {
        answers.push_back(vec);
        return;
    }
    for(int i=minValue;i<=rest;++i) {
        if(rest%i == 0) {
            vec.push_back(i);
            solve(vec, rest/i, i);
            vec.erase(prev(vec.end()));
        }
    }
}
int main() {
    vector<int> tmp;
    while(cin >> N and N) {
        if(N <= 1) {
            cout << "0\n";
            continue;
        }
        answers.clear();
        solve(tmp, N);
        cout << answers.size() - 1 << '\n';
        for(auto answer: answers) {
            if(answer.size() == 1) break;
            for(int i=0;i<answer.size();++i) {
                cout << answer[i] << " \n"[i==answer.size()-1];
            }
        }
    }
    return 0;
}
