#include <stdio.h>


int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        printf("\'C\' can use printf(\"%%d\",n); to show integer like %d\n", N);
    }
    return 0;
}