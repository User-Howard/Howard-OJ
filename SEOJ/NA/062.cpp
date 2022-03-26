#include<iostream>
#include<list>
using namespace std;


int arr[81+2];
bool solved = false;
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
        solved = true;
        for(int i=0;i<81;++i)   
            cout << arr[i];
        cout << '\n';
    }
    else{
        bool able_to[10]={0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i=0;i<81;i++){
            if(same_row(idx, i) or same_col(idx, i) or same_block(idx, i)){
                able_to[arr[i]] = 0;
            }
        }
        for(int i=1;i<10;i++){
            if(solved)
                return;
            if(!able_to[i])
                continue;
            arr[idx] = i;
            solveSudoku(arr);
            arr[idx] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        for(int i=0;i<81;i++)
            arr[i] = (s[i]=='.'? 0: s[i]-'0');
        solved = false;
        solveSudoku(arr);
        if(!solved)
            cout << "No solution." << '\n'; 
    }
    return 0;
}
