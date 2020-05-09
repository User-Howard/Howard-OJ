#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main(void){
	int count,r,li[100][100];
	int l1,l2,l3,Ans;
	scanf("%d",&count);
	
	for(int i=0;i<count;i++){
		scanf("%d",&r);
		
		for(int j=0;j<r;j++){
			scanf("%d",&li[i][j]);
		}
		
		sort(li[i],li[i] + r);
		Ans=0;
		for(l1=0;l1<r;l1++){
			for(l2=l1+1;l2<r;l2++){
				for(l3=l2+1;l3<r;l3++){
					//printf("1=%d 2=%d 3=%d\n",li[i][l1],li[i][l],li[i][l3]);
					if(li[i][l1]*li[i][l1] + li[i][l2]*li[i][l2] == li[i][l3]*li[i][l3]){
						Ans++;
					}
				}
			}
		}
		printf("%d\n",Ans);
	}
	
	return 0;
}
