#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<pair<int, int> > Nums;
    for(int i = 0;i<N;++i) {
        int a, b;
        cin>>a>>b;
        Nums.push_back(make_pair(a*a+b*b, 1000*a+b));
    }
    sort(Nums.begin(), Nums.end());
    cout<<Nums[Nums.size()-2].second/1000<<' '<<Nums[Nums.size()-2].second%1000<<'\n';
    return 0;
}