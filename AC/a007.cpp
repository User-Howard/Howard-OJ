#include <iostream>
#include <cmath>
using namespace std;

inline bool is_prime(int a)
{
	float n_sqrt;
	if (a == 2 || a == 3)
		return 1;
	if (a % 6 != 1 && a % 6 != 5)
		return 0;
	n_sqrt = floor(sqrt((float)a));
	for (int i = 5; i <= n_sqrt; i += 6)
	{
		if (a % (i) == 0 | a % (i + 2) == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		if (is_prime(a))
			printf("y\n");
		else
			printf("n\n");
	}
	return 0;
}
