#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

template < typename T >
T GCD(T a, T b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}

int main(void){
    int N, dat, rest;
    int arr[52];
    while(scanf("%d", &N) == 1, N){
        for(int i=0;i<N;i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+N);

        dat = 0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(GCD(arr[i], arr[j]) == 1)
                    dat++;
            }
        }
        if(dat==0)
			printf("No estimate for this data set.\n");
		else
			printf("%0.6lf\n",sqrt((double)((N*(N-1)/2)*6)/dat));
    }
    return 0;
}
