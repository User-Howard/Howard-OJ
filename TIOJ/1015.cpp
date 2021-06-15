#include <iostream>
#include <cmath>
using namespace std;


int A, B;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>A>>B && A && B){
        int n = min(A, B)-1;
        cout << (uint64_t)A*B*(n+1)+(uint64_t)n*(n+1)*(2*n+1)/6-(uint64_t)(n+1)*n/2*(A+B) << '\n';
	}
	return 0;
}

// finish time: 3	min, 52	sec, 70	hsec
