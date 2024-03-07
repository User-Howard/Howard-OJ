#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void solve(int N,int order[]);
void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();

vector<int> train_at;
stack<int> sta0, sta1, sta2;
void movementA(int x) {
    sta0.pop();
    sta1.push(x);
    push_train();
    train_at[x] = 1;
}
void movementB(int x) {
    sta1.pop();
    sta2.push(x);
    move_station_1_to_2();
    train_at[x] = 2;
}
void movementC(int x) {
    sta2.pop();
    sta1.push(x);
    move_station_2_to_1();
    train_at[x] = 1;
}
void solve(int N, int order[]) {
    train_at.resize(N+1);
    for(int i=N;i>=1;--i) sta0.push(i);

    for(int i=0;i<N;++i) {
        const int train = order[i];
        while(train_at[train] == 0) {
            movementA(sta0.top());
        }
        while(train_at[train] == 1) {
            movementB(sta1.top());
        }
        while (sta2.top() != train){
            movementC(sta2.top());
        }
        sta2.pop();
        pop_train();
    }
}