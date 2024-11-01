#include <stdio.h>
#include <math.h>


float roundAt(float value, int pos) {
    int pow10 = 1;
    for(int i=0;i<pos;++i) pow10 *= 10;
    return roundf(value*pow10) / pow10;
}
int main() {
    int W;
    float H;
    scanf("%d %f", &W, &H);
    printf("%.1f\n", roundAt(W/H/H, 1));
    return 0;
}