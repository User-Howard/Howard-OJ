//
//  2276.cpp
//  111學年度建國中學校內資訊能力競賽：初試
//
//  Created by 吳浩瑋 on 2022/9/13.
//
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

vvi block(6);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<6;++i) {
        int k;
        cin >> k;
        for(int j=0;j<k;++j) {
            int a;
            cin >> a;
            block[a-1].push_back(i);
        }
    }
    int answer = 1;
    for(int i=0;i<6;++i) {
        answer *= 6-block[i].size();
    }
    cout << answer << '\n';
    return 0;
}
