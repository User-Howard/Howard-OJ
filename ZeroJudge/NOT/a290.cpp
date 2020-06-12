#include<iostream>
#include<set>
#include<stdio.h>
#include<string.h>
using namespace std;


int N, M, s1, s2, start, goal;
set<int >arr[802];
int visited[802];
bool dfs(int );


int main(void){
    while(scanf("%d %d", &N, &M) == 2){
        memset(visited, -1, sizeof(visited));
        for(int i=0;i<N;i++){
            arr[i].clear();
        }

        for(int i=0;i<M;i++){
            scanf("%d %d", &s1, &s2);
            arr[s1].insert(s2);
        }

        scanf("%d %d", &start, &goal);
        if(dfs(start) == 1){
            cout<<"Yes!!!\n";
        }
        else{
            cout<<"No!!!\n";
        }
    }

    return 0;
}
bool dfs(int N){
    if(arr[N].count(goal))
        return 1;
    if(arr[N].count(-1) || visited[N] == 1)
        return 0;
    else{
        for(set<int>::iterator it=arr[N].begin(); it!=arr[N].end(); ++it){
            visited[*it]=1;
            if(dfs(*it))
                return 1;
            visited[*it]=0;
        }
    }
    return 0;
}
