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
	vector < int > arr;
	arr.push_back(2);
	
	for(int i=3;i<46344;i+=2)
	{
		is_sam=true;
		for(int j=0;arr[j]<sqrt(i)+2;j++)
		{
			if(i % arr[j] == 0)
			{
				is_sam=false;
				break;
			}

		}
		if(is_sam)	
		{
			arr.push_back(i);
			 cout<<i<<endl;
		}

	}
	cout<<arr.size()<<endl;
	while(scanf("%d",&a)!=EOF)
	{
		is_sam=true;
		for(int j=0;arr[j]<sqrt(a)+2;j++)
		{
			if(a % arr[j] == 0)
			{
				is_sam=false;
				break;
			}
		if(is_sam)
			printf("1\n");
		else
			printf("0\n");
		}
	}
	return 0;

}
