#include<iostream>
#include<map>
using namespace std;


int main(void){
	int a,i;
	map<int,int>li;
	while(scanf("%d",&a) != EOF){
		i=2;
		li.clear();
		while(a != 1){
			if(a%i == 0 || a==i){
				li[i]++;
				a/=i;
			}
			else
				i++;

		}
		bool fir=1;
		for(int j=2;j <= i;j++){
			if(li[j] > 1){
				if(! fir)
					printf(" * ");

				printf("%d^%d",j,li[j]);
				fir=false;
			}
			else if(li[j] == 1){
				if(! fir)
					printf(" * ");

				printf("%d",j);
				fir=false;
			}
		}
		printf("\n");
	}

	return 0;
}
