#include<iostream>
using namespace std;


int main(void)
{
	int h1,h2,m1,m2;
	scanf("%d%d",&h1,&m1);
	scanf("%d%d",&h2,&m2);
	int MH,MM;
	
	if((h1*60+m1) >= (h2*60+m2))
		h2+=24;

	MM=m2-m1;
	MH=h2-h1;
	if(MM <0)
	{
		MM+=60;
		MH-=1;
	}


	printf("%d %d",MH,MM);
	return 0;
}
