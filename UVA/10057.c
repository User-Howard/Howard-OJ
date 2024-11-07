#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[1000005];
int cmp(const void* a, const void* b) {
    return *(int* )a - *(int* )b;
}
int main() {
    int N;
    while(scanf("%d", &N)==1) {
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, N, sizeof(int), cmp);
        int l, r;
        if(N%2) {
            l = r = arr[N/2];
        } else {
            l = arr[N/2-1];
            r = arr[N/2];
        }
        int cnt = 0;
        for(int i=0;i<N;++i) {
            if(l<=arr[i] && arr[i]<=r) {
                cnt++;
            }
        }
        printf("%d %d %d\n", l, cnt, r-l+1);
    }
    return 0;
}
