#include <iostream>
using namespace std;


int main()
{
	int N,Ans=1;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		Ans+=i; 
	}
	
	printf("%d",Ans);
    return 0;
}
