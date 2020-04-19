#include <iostream>
using namespace std;

int main(void)
{
	string inp;
	while (getline(cin, inp))
	{
		if (inp == "EOF")
		{
			return 0;
		}
		bool t = true;
		for (int i = 0; i < inp.size() / 2; i++)
		{
			if (inp[i] != inp[inp.size() - 1 - i])
			{
				t = false;
			}
		}
		if (t)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
