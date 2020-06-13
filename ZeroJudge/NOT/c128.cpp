#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
using namespace std;


int N, K, dest, count_r;
string s1, s2, From, To;
map<string, stack<pair<string, int > > >arr;
bool dfs(string );


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>N>>K and (N!=0 and K!=0)){
        count_r=0;
        for(int i=0;i<K;i++){
            cin>>s1>>s2>>dest;
            arr[s1].push(make_pair(s2, dest));
            arr[s2].push(make_pair(s1, dest));
        }
        cin>>From>>To;
        cout<<dfs(From)<<endl;
        map<string, stack<pair<string, int > > >rest;

    }

    return 0;
}
bool dfs(string str){
    int min_r=0, rest;
    for(;arr[str].size();arr[str].pop()){
        rest=dfs(arr[str].top().first());
        if(rest!=0)
            min_r=min(min_r, rest);
    }
    return min_r;
}
