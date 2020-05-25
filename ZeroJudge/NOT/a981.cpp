#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M,r;
vector<int >arr;


int ANS(int li[],int lisize){
	for(int i=0;i<arr.size();i++){
		if( ! in_(li,lisize,arr[i]));
	}
	return 0;
}


int main(void){
	while(scanf("%d %d",&N,&M) != EOF){
		for(int i=0;i<N;i++){
			scanf("%d",&r);
			arr.push_back(r);
		}
		sort(arr.begin(),arr.end());
		
		
	}
	return 0;
}
