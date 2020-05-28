#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
	
	int a[10];
	int n,compare,com;
	int temp;
	
	scanf("%d",&n);
	
	for(int i=8;i>=0;i--){
		temp=n%10;
		a[i]=temp;
		n/=10;
		//printf("%d\n",i);
	}
	
	compare=a[6]*100+a[7]*10+a[8];
		
	sort(a,a+9);
	
	//printf("%d",compare);
	
	com=a[8]*a[8]+a[7]*a[7];
	
	if(com==compare){
		printf("Good Morning!");
	}
	else{
		printf("SPY!");
	}
	
	
	
	
	
	return 0;
}
