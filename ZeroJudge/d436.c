#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char S[11];
int N;
void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse(int l, int r) {
    int i=l, j=r;
    while(i<j) {
        swap(&S[i], &S[j]);
        i++, j--;
    }
}
int _next_permutation() {
    int p = N-1;
    while(p>=1 && S[p-1]>=S[p]) p--;
    if(p==0) return 0;
    int k=N-1;
    while(p<=k && S[k]<=S[p-1]) k--;
    swap(&S[p-1], &S[k]);
    reverse(p, N-1);

    return 1;
}
int cmp(const void *a, const void *b) {
    char ca = *(char*)a;
    char cb = *(char*)b;
    return ca-cb;
}
void solve() {
    scanf("%s", S);
    N = strlen(S);
    qsort(S, N, sizeof(char), cmp);
    char op;
    do {
        printf("%s\n", S);
    } while(_next_permutation());
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
        puts("");
    }
    return 0;
}

