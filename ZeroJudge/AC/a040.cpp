#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

bool des(int);

int main(void)
{

	int a, b;
	bool onlyone = true;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		onlyone = true;
		for (int i = a; i < b; i++)
		{
			if(des(i))
			{
				printf("%d ",i);
				onlyone=false;
			}
		}
		if(onlyone)
			printf("none\n");
		else
			printf("\n");
	}
	return 0;
}

bool des(int a)
{
	string out;
	stringstream s;
	int ans=0;
	s<<a;
	s>>out;

	for(int i=0;i<out.size();i++)
	{
		ans+=pow((int)out[i]-48,out.size());
	}
	return a == ans;
}