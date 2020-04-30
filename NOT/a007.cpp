#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool is_prime(int a){

    if(a == 1)
        return 0;
	else if(a == 2)
		return 1;
	for(int i=4;i<=sqrt(a)+1;i+=2)
	{
		if(a%i-1 == 0 || a%i+1 == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main(){
	int a;
	bool is_sam;
	vector < int > arr(50000,2147483647);
	arr.push_back(2);
	
	for(int i=3;i<2147483647;i+=2)
	{
		//cout<<i<<endl;
		for(int j=0;arr[j]<=sqrt(a)+1;j++)
		{
			is_sam=false;
			if(i % arr[i] == 0)
			{
				is_sam=true;
				break;
			}

		}
		if(! is_sam)	
		{
			arr.push_back(i);
			cout<<i<<endl;
		}

	}
	cout<<arr.size()<<endl;
	while(scanf("%d",&a)!=EOF)
	{
		if(is_prime(a))
			printf("質數\n");
		else
			printf("非質數\n");
	}
	return 0;
}