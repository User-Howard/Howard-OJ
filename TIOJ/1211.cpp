#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;



int N, M;
const int MAX_N = 1e4;
const int MAX_M = 1e6;
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
    while(cin>>N>>M && N!=0 && M!=0){
        for(int m=0;m<M;m++)
            cin>>Lines[m].from>>Lines[m].to>>Lines[m].v;
        sort(Lines, Lines+M);
        for(int i=1;i<=N;i++)
            father[i] = i;
        int ans=0, cnt=0;
        for(int i=0;i<M;i++){
            L l=Lines[i];
            if(find_father(l.from)!=find_father(l.to)){
                father[find_father(l.from)] = find_father(l.to);
                ans += l.v;
                cnt++;
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
