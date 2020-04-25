#include <iostream>
using namespace std;

int co = 0;

bool li[5][5] = {
	{1, 0, 1, 0, 0},
	{1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1},
	{1, 0, 1, 0, 0},
	{1, 0, 1, 0, 0}};
void Res(int x, int y)
{
	if (li[x][y])
	{
		co++;
		li[x][y] = 0;
	}
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			
				Res(x + i, x + j);
				printf("1");
			
		}
	}
	return;
}

int main(void)
{
	printf("1");
	Res(3, 3);
	printf("%d",co);
	return 0;
}
