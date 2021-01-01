#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define mid (low+high)/2


int data_arr[100], val;
int binary(int low, int high){
    if(data_arr[low] == val)
        return low;
    else if(low>high)
        return -1;

    if(val<data_arr[mid]) {
        printf("%d is between %d[%d] and %d[%d], find left\n", val, low, data_arr[low], mid, data_arr[mid]);
        high=mid-1;
    }
    else if(val>data_arr[mid]) {
        printf("%d is between %d[%d] and %d[%d], find right\n", val, mid, data_arr[mid], high, data_arr[high]);
        low=mid+1;
    }
    return binary(low, high);
}

int main(){
    for(int i=0,var=1; i<100; i++) {
		data_arr[i]=var;
		var+=rand()%5+1;
	}
	scanf("%d", &val);
    for(int j=0; j<100; j++) {
        printf("%2d [%3d]  ", j, data_arr[j]);
    }
    printf("%d\n", binary(0, 99));


	return 0;
}
