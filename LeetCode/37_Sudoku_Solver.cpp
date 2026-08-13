class Solution {
    vector<vector<char> > *bdPtr;
    bool check(int x, int y) {
        auto& bd = *bdPtr;
        for(int i=0;i<9;++i) {
            if(i!=y and bd[x][y]==bd[x][i]) return false;
            if(i!=x and bd[x][y]==bd[i][y]) return false;
            int nx = (x/3)*3 + (i/3);
            int ny = (y/3)*3 + (i%3);
            if((nx!=x or ny!=y) and bd[x][y]==bd[nx][ny]) return false;
        }
        return true;
    }
    bool solve(int pos) {
        auto& bd = *bdPtr;
        while(pos<81 and bd[pos/9][pos%9]!='.') pos++;
        if(pos==81) return true;
        for(char c='1';c<='9';++c) {
            bd[pos/9][pos%9] = c;
            if(not check(pos/9, pos%9)) continue;
            if(solve(pos+1)) return true;
        }
        bd[pos/9][pos%9] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bdPtr = &board;
        cout << solve(0);
    }
};
