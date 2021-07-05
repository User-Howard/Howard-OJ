#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define w first
#define h second
typedef pair<int, int> pii;


vector<pii> dolls;
vector<int> lis;
bool cmp(const pii a, const pii b){
    if(a.w == b.w)
        return a.h > b.h;
    else
        return a.w < b.w;
}
void solve(){
    int M;
    cin >> M;
    dolls.resize(M);
    for(int i=0;i<M;i++)
        cin >> dolls[i].w >> dolls[i].h;
    sort(dolls.begin(), dolls.end(), cmp);
    lis.clear();
    for(pii i:dolls){
        if(lis.empty() || i.h > *(lis.end() - 1))
            lis.push_back(i.h);
        else
            *lower_bound(lis.begin(), lis.end(), i.h) = i.h;
    }
    cout << lis.size() << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
