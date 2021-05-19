#include<iostream>
using namespace std;


int main(void){
    int b1,b2,bt;
    bool flag = false;
    scanf("%d %d %d",&b1,&b2,&bt);
    b1 = !!b1;
    b2 = !!b2;
    if((b1 and b2 ) == bt){
        printf("AND\n");
		flag = true;    	
	}
    if((b1 or b2 ) == bt){
    	printf("OR\n");
    	flag = true;
	}
        
    if((b1 xor b2 ) == bt){
    	printf("XOR\n");
    	flag = true;
	}
        

    if(!flag)
        printf("IMPOSSIBLE\n");
    return 0;
}
