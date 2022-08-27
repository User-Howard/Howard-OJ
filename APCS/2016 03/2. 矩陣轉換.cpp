#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int R, C, M;
    while (cin >> R >> C >> M) {
        vector<vector<int>> nums(max(R, C), vector<int>(max(R, C), 0));
        vector<vector<int> > t(max(R, C), vector<int>(max(R, C), 0));
        vector<int>act(M);
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                cin >> nums[i][j];
        for(int i=0;i<M;++i)
            cin >> act[i];
        for(int c=M-1;c>=0;--c){
            if(act[c]){
                for(int i=0;i<R;++i)
                    for(int j=0;j<C;++j)
                        t[i][j] = nums[R-1-i][j];
                nums = t;
            }
            else{
                for(int i=0;i<C;++i)
                    for(int j=0;j<R;++j)
                        t[i][j] = nums[j][C-1-i];
                nums = t;
                swap(R, C);
            }
        }
        cout << R << ' ' << C << '\n';
        for(int i=0;i<R;++i){
            cout << nums[i][0];
            for(int j=1;j<C;++j)
                cout << ' ' << nums[i][j]; 
            cout << endl;
        }
    }
    return 0;
}
