#include <iostream>
using namespace std;

    
int main(void)
{
	long long int f_Ans[30001],g_Ans[30001];
	f_Ans[1]=1;
	g_Ans[1]=1;
	for(int i=2;i<30001;i++)
		f_Ans[i]=f_Ans[i-1]+i;
	for(int i=2;i<30001;i++)
		g_Ans[i]=f_Ans[i]+g_Ans[i-1];
		
	int test;
	while(scanf("%d",&test) != EOF)
		printf("%lld %lld\n",f_Ans[test],g_Ans[test]);
    return 0;
}
