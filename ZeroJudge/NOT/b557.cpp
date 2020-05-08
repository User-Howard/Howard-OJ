#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
	int count,r,li[100][100];
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		scanf("%d",&r);
		for(int j=0;j<r;j++){
			scanf("%d",&li[i][j]);
		}
		sort(li[i],li[i] + r);
		cout<<li[i][0]<<li[i][1]<<endl;
	}
	
	int l1,l2,l3;
	for(int i=0;i<count;i++){
		for(l1=0;l1<count;l1++){
			for(l2=l1+1;l2<count;l2++){
				for(l3=l2+1;l1<count;l3++){
					if(l1 + l2 > l3){
						printf("%d %d %d",l1,l2,l3);
					}
				}
			}
		}
	}
	return 0;
}
