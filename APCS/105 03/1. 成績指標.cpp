#include<stdio.h>
#include<algorithm>
using namespace std;


int main(){
    int N, arr[22];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    for(int i=0;i<N;i++)
        printf("%d ", arr[i]);
    puts("");
    int i, n;
    if(arr[0]>=60)
        puts("best case");
    else{
        n=0;
        for(i=0;i<N;i++){
            if(arr[i]<60){
                n=max(n, arr[i]);
            }
        }
        printf("%d\n", n);
    }

    if(arr[N-1]<60)
        puts("worst case");
    else{
        n=100;
        for(i=N-1;i>=0;i--){
            if(60<=arr[i]){
                n=min(n, arr[i]);
            }
        }
        printf("%d\n", n);
    }

    return 0;
}
