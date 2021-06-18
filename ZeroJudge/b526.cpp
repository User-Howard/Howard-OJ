#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, a, b, c = 0, ans = 0;
	scanf("%d\n", &n);
	long aa [200000] = { 0 };
	scanf("%d\n", &m);
	for (m > 0;m > 0;m--) {
		scanf("%d", &a);
		scanf("%d", &b);
		for (a >= 0 && a < n && b>0 && b <= n;a <= b;a++) {
			aa [a - 1] = aa [a - 1] + 1;
		}

	}
	for (c = 0;c <= n - 1;c++) { if (aa [c] % 2 == 0) ans = ans + 1; }

	printf("\n");

	printf("%d\n", ans);

	return 0;
}

