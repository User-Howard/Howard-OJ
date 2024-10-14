#include <stdio.h>
#include <math.h>


int main() {
    int N;
    float M;
    scanf("%d %f", &N, &M);
    printf("%.1f\n", round(1.0*N/M/M*10)/10);

    return 0;
}
// 複習malloc