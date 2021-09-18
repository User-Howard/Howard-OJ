#include <iostream>
using namespace std;


int main(void){
	int a;
	while (cin >> a){
		int i = 1, doular, sum = 0;
		for (i = 1; i <= a; i++){
			cin >> doular;
			sum += doular * i;
		}
		printf("%d", sum);
	}
	return 0;
}
