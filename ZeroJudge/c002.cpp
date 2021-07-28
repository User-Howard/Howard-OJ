#include <iostream>
using namespace std;


int main(){
	int N;
	while(cin >> N and N){
		cout << "f91(" << N << ") = ";
		if(N < 101)
			cout << 91 << endl;
		else
			cout << N-10 << endl;
	}
	return 0;
}
