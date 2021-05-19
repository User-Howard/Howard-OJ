#include<stdio.h>
#include<vector>
using namespace std;


int sum;
bool isok(int n, vector<int >arr, int x){
    if(arr.size() == 0)
        return 1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == x){
            return 0;
        }
    }
    for(int i=0;i<arr.size();i++){
        if((x+arr.size()-i)<n && (x+arr.size()-i)>=0 && arr[i] == (x+arr.size()-i))
            return 0;
        if((x-arr.size()+i)<n && (x-arr.size()+i)>=0 && arr[i] == (x-arr.size()+i))
            return 0;
    }
    return 1;
}
void queen(int n, vector<int >arr){
    if(n == arr.size()){
        sum++;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == arr[i]){
                    printf("Q");
                }
                else{
                    printf("x");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    else{
        for(int i=0;i<n;i++){
            if(isok(n, arr, i)){
                arr.push_back(i);
                queen(n, arr);
                arr.pop_back();
            }
        }
    }
}
int main(void){
    int N;
    vector<int >arr;

    while(scanf("%d", &N) == 1 && N>=1){
        sum=0;
        printf("\n");
        queen(N, arr);
        printf("%d\n", sum);
    }
    return 0;
}
