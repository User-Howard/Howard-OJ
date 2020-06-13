#include<iostream>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
using namespace std;


int N, K, dest, count_r;
string s1, s2, From, To;
map<string, set<pair<string, int > > >arr;
map<string, bool>visit;
int dfs(string );
bool isfine(string );


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>N>>K and (N!=0 and K!=0)){
        count_r=0;
        for(int i=0;i<K;i++){
            cin>>s1>>s2>>dest;
            arr[s1].insert(make_pair(s2, dest));
            arr[s2].insert(make_pair(s1, dest));
        }
        cin>>From>>To;

        isfine(From);
        // cout<<dfs(From)<<endl;
        // map<string, stack<pair<string, int > > >rest=arr;

    }

    return 0;
}
/*
int dfs(string str){
    int min_r=0, rest;
    if(arr[str].size() == 0)
        return 0;
    for(;arr[str].size();){
        // rest=dfs(arr[str].top().first());
        if(rest!=0)
            min_r=min(min_r, rest);
    }
    return min_r;
}
*/
bool isfine(string str){
    visit[str]=1;
    cout<<str<<endl;
    for(set<pair<string, int>>::iterator it=arr[str].begin();it!=arr[str].end(); ++it){
        if(visit[(*it).first()]
           != 1 and(*it.first() == To || isfine(*it.first())))
            return 1;
    }

}
