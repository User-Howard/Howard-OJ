#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> li;
	int a;
	while(scanf("%d",&a) && a){
		printf("Discarded cards: ");
		li.clear();
		for(int i=1;i<=a;i++)
			li.push_back(i);
		while (li.size()>=3)
		{
			printf("%d, ",li.front());
			li.erase(li.begin());
			li.push_back(li.front());
			li.erase(li.begin());
		}
		if(a!=1)
			printf("%d\nRemaining card: %d\n",li[0],li[1]);
		else
			printf("\nRemaining card: %d\n",li[0]);
		
	}


	return 0;
}