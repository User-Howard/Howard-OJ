#include <iostream>
#include <queue>
using namespace std;


struct InksTemp{
    uint8_t step, x, y;
    uint8_t color;
    InksTemp(int step_, int color_, int x_, int y_){
        step = step_;
        color = color_;
        x = x_;
        y = y_;
    }
};
int N;
int board[1002][1002];
int Obs_color;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int color_to_int(char c){
    int color;
    if(c == 'R')
        color = (1<<0);
    else if(c == 'P')
        color = (1<<0) + (1<<1);
    else if(c == 'B')
        color = (1<<1);
    else if(c == 'G')
        color = (1<<1) + (1<<2);
    else if(c == 'Y')
        color = (1<<2);
    else if(c == 'O')
        color = (1<<0) + (1<<2);
    else if(c == 'D')
        color = (1<<0) + (1<<1) + (1<<2);
    return color;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        queue<InksTemp> inks;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)
                board[i][j] = 0;
        }
        int r = 0;
        cin >> N;
        for(int i=0;i<3;++i){
            char c;
            int sx, sy;
            cin >> c >> sx >> sy;
            r |= color_to_int(c);
            inks.push(InksTemp(0, color_to_int(c), sx, sy));
        }
        int step_now = 0, max_answer = -1;
        char c;
        cin >> c;        
        if(c == 'D'){
            if(r == 7)
                cout << N*N << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        else if(color_to_int(c) - r > 0){
            cout << 0 << '\n';
            continue;
        } 
        while(!inks.empty()){
            while(!inks.empty() and inks.front().step < step_now){
                InksTemp p = inks.front(); inks.pop();
                board[p.x][p.y] |= p.color;
                for(int i=0;i<8;++i){
                    int rx = p.x + dx[i], ry = p.y + dy[i];
                    if(rx<0 or ry<0 or rx>=N or ry>=N)
                        continue;
                    if(board[rx][ry] == 7 or (board[rx][ry] == p.color))
                        continue;
                    inks.push(InksTemp(p.step+1, p.color, rx, ry));
                }
            }
            int answer = 0;
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(board[i][j] == color_to_int(c))
                        answer ++;
                }
            }
            max_answer = max(max_answer, answer);
            step_now++;
            // cout << answer << '\n';
            // cout << '\n';
        }
        cout << max_answer << '\n';
    }
    return 0;
}
