#include<iostream>
#include<set>
#include<stdio.h>
using namespace std;


int N, M, s1, s2, start, goal;
set<int >arr[802];
int visited[802];
bool dfs(int );


int main(void){
    while(scanf("%d %d", &N, &M) == 2){
        for(int i=0;i<N;i++){
            arr[i].clear();
            visited[i]=0;
        }
        for(int i=0;i<M;i++){
            scanf("%d %d", &s1, &s2);
            arr[s1].insert(s2);
        }

        scanf("%d %d", &start, &goal);
        if(dfs(start) == 1){
            puts("Yes!!!\n");
        }
        else{
            puts("No!!!\n");
        }
    }

    return 0;
}
bool dfs(int N){
    visited[N] = 1;
    for(set<int>::iterator it=arr[N].begin(); it!=arr[N].end(); ++it){
        if(visited[*it] != 1 and (*it == goal || dfs(*it)))
            return 1;
    }
    return 0;
}
