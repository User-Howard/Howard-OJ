#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    map<int, int> m;
    int answer = 1;
    int pointer = 0;
    for(int i=0;i<N;++i) {
        while(pointer < N && m[Nums[pointer]]==0) {
            m[Nums[pointer++]]++;
        }
        answer = max(pointer - i, answer);
        m[Nums[i]]--;
    }
    cout << answer << '\n';
    return 0;
}