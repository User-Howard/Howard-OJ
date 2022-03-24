//sprout 23
#include<cstdio>
#include<algorithm>
using namespace std;

void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
void solve(int N,int order[]){
	int sa[5005],sb[5005];
	int sa_cnt=0,sb_cnt=0,cnt=0;
	for(int t=0;t<N;++t){
		while(order[t]>cnt){
			sa[sa_cnt++]=++cnt;
			push_train();
		}
		if(find(sa,sa+sa_cnt,order[t])!=sa+sa_cnt){
			while(sa[sa_cnt-1]!=order[t]){
				sb[sb_cnt++]=sa[sa_cnt-1],sa_cnt--;
				move_station_1_to_2();
			}
			sb[sb_cnt++]=sa[sa_cnt-1],sa_cnt--;
			move_station_1_to_2();
		}
		while(sb[sb_cnt-1]!=order[t]){
			sa[sa_cnt++]=sb[sb_cnt-1],sb_cnt--;
			move_station_2_to_1();
		}
		sb_cnt--;
		pop_train();
	}
	return;
}