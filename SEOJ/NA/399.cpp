#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int, int> > vec(N);
    for(int i=0;i<N;++i)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());
    for(int i=0;i<N;++i){
        
    }
    return 0;
}