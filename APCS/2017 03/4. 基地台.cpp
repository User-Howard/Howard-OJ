#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, K;
vector<int> point;
int check(int D){
    int l = 0, cnt = 0;
    for(int i=0;i<N;++i){
        if(!(point[i] <= l)){
            ++cnt;
            l = point[i] + D;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    point.resize(N);
    for(int i=0;i<N;++i)
        cin >> point[i];
    sort(point.begin(), point.end());
    int l = 0, r = *(point.end()-1) - *(point.begin());
    while(r-l>1){
        int mid = (r + l) / 2;
        if(check(mid) <= K)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
    return 0;
}