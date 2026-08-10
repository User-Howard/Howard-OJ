class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9];
        bool cols[9][9];
        bool boxes[9][9];
        fill(&rows[0][0], &rows[0][0]+9*9, 0);
        fill(&cols[0][0], &cols[0][0]+9*9, 0);
        fill(&boxes[0][0], &boxes[0][0]+9*9, 0);
        for(int i=0;i<9;++i) {
            for(int j=0;j<9;++j) {
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '1';
                int row_id = i;
                int col_id = j;
                int box_id = (i/3)*3 + (j/3)%3;

                if(rows[row_id][num] or cols[col_id][num] or boxes[box_id][num]) {
                    return false;
                }
                rows[row_id][num] = cols[col_id][num] = boxes[box_id][num] = true;
            }
        }
        return true;
    }
};
