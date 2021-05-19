#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int N, count = 0;
    while (scanf("%d", &N) != EOF, N!=1){
        for (int i = 0; i <= 14; i++){
            if (pow(2, i) >= N){
                printf("Case %d: %d\n", ++count, i);
                break;
            }
        }
    }
    return 0;
}