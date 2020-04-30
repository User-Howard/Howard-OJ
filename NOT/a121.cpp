
#include<iostream>
#include<math.h>
using namespace std;


int prime(int a)
{
    if(a == 1)
        return 1;
	for(int i=2;i<=sqrt(a)+1;i++)
	{
		if(a%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main(){
	int mi,mx;
	while(scanf("%d%d",&mi,&mx)!= EOF){
		int s=0;
        if(mx-mi >1000){
            printf("0\n");
            continue;
        }
		for(int v=mi;v<mx+1;v++){
		    if(prime(v))
    			s+=1;
	    	
        }
		printf("%d\n",s);
	}
	
	return 0;
}
