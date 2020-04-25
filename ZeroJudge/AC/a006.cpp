#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
	int a,b,c,rest;
	scanf("%d%d%d",&a,&b,&c);
	rest=b*b-4*a*c;
	
	if(rest==0)
		printf("Two same roots x=%d",(int)(-b/(2*a)));
	else if(rest<0)
		printf("No real root");
	else
		printf("Two different roots x1=%d , x2=%d",(int)(-b+ sqrt(rest))/(2*a), (int)(-b-sqrt(rest))/(2*a));
		
	return 0;
}
