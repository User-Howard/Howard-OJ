#include <iostream>
using namespace std;

int main(void)
{
	string st;
	while (getline(cin, st) && st != "")
	{
		st+=" ";
		int sp = 0, r = st.size();
		for (int i = 0; i < r; i++)
		{
			if (122 >= st[i] && st[i] <= 65)
			{
				sp++;
				while (122 >= st[i] && st[i] <= 65 && i < r)
				{
					i++;
				}
			}
		}
		printf("%d\n", sp);
	}
	return 0;
}