#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    set<int> s;
    int answer = 1;
    int pointer = 0;
    for(int i=0;i<N;++i) {
        if(s.count(Nums[i])) {
            while(Nums[pointer] != Nums[i]) {
                s.erase(Nums[pointer++]);
            }
            s.erase(Nums[i]);
            pointer++;
        }
        s.insert(Nums[i]);
        answer = max(answer, i-pointer+1);
    }
    cout << answer << '\n';
    return 0;
}
