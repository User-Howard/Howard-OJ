#include <iostream>
using namespace std;


int main(void)
{
    int N;
    while(scanf("%d",&N) && N){
        for(int i=1;i<N;i++){
            if(i%7)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
