#include <iostream>
using namespace std;

int main() {
	unsigned long long NminusM, buffer;
	while (scanf("%d",&NminusM)==1, NminusM) {
		buffer = NminusM * 10;
		if (!(buffer % 9))
			cout << buffer / 9 - 1 << ' ';
		cout << buffer / 9 << '\n';
	}
}
