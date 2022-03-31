#include<iostream>
#include<list>
using namespace std;


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
    if(solved)
        return;
    int idx = find_block(arr);
    if(idx == -1){
        solved = true;
        for(int i=0;i<81;++i)
            cout << arr[i];
        cout << '\n';
    }
    else{
        bool can_choose[10]={0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for(int i=0;i<81;i++){
            if(same_row(idx, i) or same_col(idx, i) or same_block(idx, i)){
                can_choose[arr[i]] = false;
            }
        }
        for(int i=1;i<10;i++){
            if(solved)
                return;
            if(!can_choose[i])
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
        int arr[81+5];
        for(int i=0;i<81;i++)
            arr[i] = (s[i]=='.'? 0: s[i]-'0');
        solved = false;
        for(int i=0;i<81;++i){
            if(arr[i] == 0)
                continue;
            for(int j=0;j<81;++j){
                if(i == j)
                    continue;
                if(!same_row(i, j) and !same_col(i, j) and !same_block(i, j))
                    continue;
                if(arr[i] == arr[j])
                    goto END;
            }
        }
        solveSudoku(arr);
        END:
        if(!solved)
            cout << "No solution." << '\n';
    }
    return 0; 
}
