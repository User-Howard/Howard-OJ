#include<iostream>
using namespace std;


int main(void){
	long long int N,a,b,c;
	scanf("%lld",&N);
	while(N--){
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a == 1)
			printf("%lld\n",b+c);
		else if(a == 2)
			printf("%lld\n",b-c);
		else if(a == 3)
			printf("%lld\n",b*c);
		else if(a == 4)
			printf("%lld\n",b/c);
	}
	return 0;
}
