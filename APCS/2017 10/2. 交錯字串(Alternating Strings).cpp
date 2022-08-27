//
//  交錯字串(Alternating Strings).cpp
//  APCS
//
//  Created by 吳浩瑋 on 2022/8/27.
//
#include <iostream>
#include <vector>
using namespace std;


inline bool isUpper(char c) {
    return c <= 'Z';
}
int main() {
    int K;
    string S;
    vector<int> vec;
    cin >> K >> S;
    vec.push_back(1);
    for(int i=1;i<S.size();++i) {
        if(isUpper(S[i-1]) == isUpper(S[i]))
            ++vec[vec.size()-1];
        else
            vec.push_back(1);
    }
    int ans = 0;
    vector<pair<int, int> > answers;
    int f=-1, l=0;
    for(int i=0;i<=vec.size();++i) {
        if(i==vec.size() and f != -1) {
            answers.push_back(make_pair(f, l));
            break;
        }
        if(vec[i] != K and f != -1) {
            answers.push_back(make_pair(f, l));
            f = -1;
        }
        if(vec[i] == K) {
            if(f == -1) {
                f = i;
                l = 1;
            } else {
                ++l;
            }
        }
    }
    int answer = 0;
    for(auto i:answers) {
        int t = i.second;
        if(i.first != 0 and vec[i.first-1]>K)
            ++t;
        if(i.first + i.second != vec.size() and vec[i.first + i.second]>K)
            ++t;
        answer = max(answer, t);
    }
    cout << answer * K << '\n';
    return 0;
}