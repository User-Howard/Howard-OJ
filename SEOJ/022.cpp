#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair


int N;
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> Nums(N);
        for(int &i : Nums) cin >> i;


        uint64_t answer = 0;
        stack<pii > sta;
        for(int i: Nums) {
            while(not sta.empty() and sta.top().fi < i) {
                answer += sta.top().se; sta.pop();
            }
            if(sta.empty()) {
                sta.push(mp(i, 1));
            } else if(sta.top().fi == i) {
                answer += sta.top().se++;
                if(sta.size() >= 2) ++answer;
            } else {
                sta.push(mp(i, 1));
                ++answer;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}