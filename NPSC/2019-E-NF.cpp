#include<iostream>
#include<queue>
#include<map>
using namespace std;


struct E{
	int mood;
	string str;
}arr[102][4];
map<char, int>li;
queue<char >que;
int N, M;
string first_string;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	li['N'] = 0;
	li['P'] = 1;
	li['S'] = 2;
	li['C'] = 3;
	cin>>N>>M>>first_string;
	for(int i=0;i<first_string.size();i++){
		que.push(first_string[i]);
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<4;j++)
			cin>>arr[i][j].mood;
		for(int j=0;j<4;j++)
			cin>>arr[i][j].str;
	}
	int now_mood=1;
	while(N--){
		que.push();//
		que.front();
	}
	return 0;
}
