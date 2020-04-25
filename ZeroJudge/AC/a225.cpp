#include<iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b) {
//  	return a%10 < b%10;
	return a%10==b%10 ?(a>b):(a%10 < b%10);
}


int main(){
	int a;
	while(scanf("%d",&a) != EOF){

		int arr[a]={0};
		for(int i=0;i<a;i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+a,compare);

	  	for (int i = 0; i < a; i++) {
	    	printf("%d ",arr[i]);
		}
        printf("\n");
	}
	return 0;
}
