#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int Case, n, m;


bool solve(){
    int a, b;
    int arr[n];
    int r=1;

    for(int i=0;i<n;i++){
        arr[i]=0;
    }

    for(int co=0;co<m;co++, r++){
        scanf("%d %d", &a, &b);
        if(arr[b-1] == 0){
        	int t=a;a=b;b=t;
		}

        if(arr[a-1]==0 and arr[b-1]==0){
            arr[a-1] = r;
            arr[b-1] = r;
        }
        else if(arr[a-1]==0 and arr[b-1]!=0){
            arr[a-1] = arr[b-1];
        }
        else if(arr[a-1]!=0 and arr[b-1]!=0){
            int rest = arr[b-1];
            for(int i=0;i<n;i++){
                if(arr[i] == rest){
                    arr[i] = arr[a-1];
                }
            }
        }
    }


    int visited[n];
    int S=0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            S++;
            continue;
        }
        else if(visited[arr[i]] == 1){
            continue;
        }
        visited[arr[i]]=1;
        S++;
    }

    printf("Case %d: %d\n", Case++, S);
    return 0;
}
int main(void){
    Case=1;
    while(scanf("%d %d", &n, &m) == 2 and n!=0){
        solve();
    }
    return 0;
}
