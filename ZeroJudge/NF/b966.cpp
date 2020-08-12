#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector< pair<int, int> > arr;
int sum=0;
int N;


bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
void dfs(){
	
}
int main(){
    scanf("%d", &N);
    for(int i=0, f, e;i<N;i++){
        scanf("%d %d", &f, &e);
        arr.push_back(make_pair(f, e));
    }

    sum = 0;
    sort(arr.begin(), arr.end(), cmp);
    while(not arr.empty()){
    	int f=arr[0].first, e=arr[0].second;
    	sum+=e-f;
    	while(not arr.empty()){
			if(arr.front().first<e){
    			sum+=arr.front().first-e;
    			arr.erase(arr.begin(), arr.begin()+1);
			}
			else
				break;
		}
	}
	printf("%d\n", sum);
    return 0;
}
