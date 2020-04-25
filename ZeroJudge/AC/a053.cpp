#include<iostream>
using namespace std;


int main(){
	int a;
	while(scanf("%d",&a) != EOF){
		if(a>40)
			printf("%d\n",100);
		else if(a>=21)
			printf("%d\n",80+(a-20));
		else if(a>=11)
			printf("%d\n",60+(a-10)*2);
		else
			printf("%d\n",a*6);

	}
	return 0;
}
/*
�����D�Ʀb 0~10 �̡A�C�D��6���C
�D�Ʀb 11~20 �̡A�q��11�D�}�l�A�C�D��2���C(�e10�D�٬O�C�D��6��)
�D�Ʀb 21~40 �̡A�q��21�D�}�l�A�C�D��1���C
�D�Ʀb 40 �H�W�̡A�@��100���C
*/
