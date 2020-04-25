#include<iostream>
#include <algorithm>
using namespace std;


int main(){
	int a;
	while(scanf("%d",&a) != EOF){

		int arr[a]={0};
		for(int i=0;i<a;i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+a);

	  	for (int i = 0; i < a; i++) {
	    	printf("%d ",arr[i]);
		}
		printf("\n");
	}
	return 0;
}
