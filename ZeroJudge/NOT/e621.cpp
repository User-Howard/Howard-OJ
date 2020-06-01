#include<iostream>
using namespace std;


int main(void){
    int N, a, b, c;
    bool fini;
    scanf("%d ",&N);
    while(N--){
        fini=true;
            scanf("%d %d %d", &a, &b, &c);
    	for(int i=a+1;i<b;i++){
    		if(i%c != 0){
    			printf("%d ",i);
    			fini=false;
    		}
		}
		if(fini)
                printf("No free parking spaces.");
		printf("\n");
	}
    return 0;
}
