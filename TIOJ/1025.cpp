#include<iostream>
#include<list>
using namespace std;

int count;
int arr[81+2];
bool same_row(int i, int j){
    return (i/9 == j/9);
}
bool same_col(int i, int j){
    return (i-j) % 9 == 0;
}
bool same_block(int i, int j){
    return (i/27 == j/27 and i%9/3 == j%9/3);
}
int find_block(int arr[81+2]){
    for(int i=0;i<81;i++){
        if(arr[i] == 0)
            return i;
    }
    return -1;
}
void solveSudoku(int arr[81+2]){
    int idx = find_block(arr);
    if(idx == -1){
        count++;
        for(int i=0;i<81;i++){
            printf("%d ", arr[i]);
            if((i+1)%9 == 0)
                printf("\n");
        }
        printf("\n");
    }
    else{
        int able_to[10]={0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i=0;i<81;i++){
            if(same_row(idx, i) or same_col(idx, i) or same_block(idx, i)){
                able_to[arr[i]] = 0;
            }
        }
        for(int i=0;i<10;i++){
            if(able_to[i] == 0)
                continue;

            arr[idx] = i;
            solveSudoku(arr);
            arr[idx] = 0;
        }
    }
}
int main(){
    for(int i=0;i<81;i++){
        scanf("%d", &arr[i]);
    }
    solveSudoku(arr);
    printf("there are a total of %d solution(s).\n", count);
    return 0;
}
