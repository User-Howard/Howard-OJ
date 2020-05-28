#include<stdio.h>

int main(){
	
	int n,t;
	int a,b,max;
	int out;
	
	scanf("%d%d",&n,&t);
	
	a=n;
	b=t;
	
	while( a!=0 and b!=0 )
        {
            if( a >= b )
            {
                a = a%b;
            }
            else if( b > a )
            {
                b = b%a;
            }
        }
        if( a >= b )
        {
            max=a;
        }
        else
        {
            max=b;
    	}
	n=n/max;
	t=t/max;
	
	n+=t;
	
	//printf("%d",n);
	
	out=0;
	
	while(n!=0){
		n/=2;
		out++;
	}
	
	out=out-1;
	
	printf("%d\n",out);
	
	return 0;
}
