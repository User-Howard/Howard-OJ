#include<iostream>
using namespace std;


int main(void){
	int x,y;
	bool ist;
	scanf("%d %d",&x,&y);
	int arr[x][y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	//AND
	printf("AND: ");
	for(int i=0;i<y;i++){
		ist = true;
		for(int j=0;j<x;j++){
			if(arr[j][i] == 0){
				ist=false;
			}
		}
		printf("%d ",ist);
	}
	printf("\n");
	//OR
	printf(" OR: ");
	for(int i=0;i<y;i++){
		ist = false;
		for(int j=0;j<x;j++){
			if(arr[j][i] == 1){
				ist = true;
			}
		}
		printf("%d ",ist);
	}
	printf("\n");
	//XOR
	printf("XOR: ");
	for(int i=0;i<y;i++){
		ist = false;
		for(int j=0;j<x;j++){
			if(arr[j][i] == 1){
				ist = !ist;
			}
		}
		printf("%d ",ist);
	}
	printf("\n");
	return 0;
}
