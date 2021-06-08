#include<iostream>
#include<cmath>
using namespace std;


int N;
int H[52];
int solve(){
    int sum = 0, average;
    for(int i=0;i<N;i++){
        cin >> H[i];
        sum += H[i];
    }
    average = sum/N;
    int ans = 0;
    for(int i=0;i<N;i++)
        ans += abs(H[i]-average);
    return ans/2;
}
int main() {
    int cases = 0;
	while(cin >> N && N){
	    cout << "Set #" << (++cases) << '\n';
        cout << "The minimum number of moves is " << solve() << ".\n";
	}
	return 0;
}

// finish time: 8	min, 19	sec, 78	hsec
