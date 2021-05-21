#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;



int N, M;
const int MAX_N = 1e5;
const int MAX_M = 2e5;
int father[MAX_N+2];
struct L{
    int from, to;
    int v;
    bool operator<(const L b){
        return v<b.v;
    }
}Lines[MAX_M+2];
int find_father(int it){
    if(father[it]==it)
        return it;
    else
        return father[it] = find_father(father[it]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>N>>M){
        for(int m=0;m<M;m++)
            cin>>Lines[m].from>>Lines[m].to>>Lines[m].v;
        sort(Lines, Lines+M);
        for(int i=0;i<N;i++)
            father[i] = i;
        int cnt=0;
        int64_t ans=0;
        for(int i=0;i<M;i++){
            L l=Lines[i];
            if(find_father(l.from)!=find_father(l.to)){
                father[find_father(l.from)] = find_father(l.to);
                ans += l.v;
                if(++cnt==N-1)
                    break;
            }
        }
        if(cnt==N-1)
            cout<<ans<<'\n';
        else
            cout<<"-1"<<'\n';
    }
	return 0;
}
/*

*/
// finish time: 3662	sec
