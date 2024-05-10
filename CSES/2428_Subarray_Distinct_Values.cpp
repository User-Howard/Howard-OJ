#include <iostream>
#include <map>
#include <algorithm>
#include <map>
using namespace std;


const int MAX_N = 2e5 + 5;

int N, M;
int Nums[MAX_N]={0};
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;++i)
        cin >> Nums[i];
    map<int, int> mp;
    int pointer = 1;
    uint64_t answer = 0;
    for(int i=1;i<=N;++i) {
        answer += i-pointer+1;
        mp[Nums[i]] ++;
        while(mp.size() > M) {
            mp[Nums[pointer]]--;
            if(mp[Nums[pointer]] == 0) mp.erase(Nums[pointer]);
            pointer++;
        }
    }
    cout << answer << '\n';
    return 0;
}
