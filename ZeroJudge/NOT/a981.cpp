#include<iostream>
#include<algorithm>
using namespace std;


int N, M, nowlimit;
int list[30], arr[30];
bool visit[30], f;

int SUM(){
	int sum=0;
	for(int i=0;i<nowlimit;i++)
		sum+=arr[i];
	return sum;
}
void BFS(int x, int T){
	if(T>nowlimit){
		if(SUM() == M){
			f=false;
			for(int i=0;i<nowlimit;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}

	}
	else{
		for(int i=x;i<N;i++){
			if(visit[i])
				continue;
			arr[T-1]=list[i];
			visit[i] = 1;
			BFS(i+1, T+1);
			visit[i] = 0;
		}
	}
	return;
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>list[i];
	
	sort(list,list+N);
	f=true;
	for(int i=0;i<N;i++){
		arr[0]=list[i];
		visit[i] = 1;
		BFS(i, 2);
		
		visit[i] = 0;
	}
	if(f)
		cout<<"-1"<<endl;
	return 0;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
int N,M,r;




int main(void){
	while(scanf("%d %d",&N,&M) != EOF){
		for(int i=0;i<N;i++){
			scanf("%d",&r);
		}
		sort(arr.begin(),arr.end());
		
		
	}
	return 0;
}
*/