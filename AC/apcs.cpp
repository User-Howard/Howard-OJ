#include<iostream>
#include<sstream>
using namespace std;


int str_int(string a){
	if(a==""){
		return 1;
	}
	int b;
	stringstream st;
	st<<a;
	st>>b;
	return b;
}

bool is_num(char a){
	if(57>=(int)a && (int)a>=48)
		return 1;
	else
		return 0;
}

int main(void){
	int i,len,le;
	string a,list;
	while(cin>>a){
		
		i=0;
		len = a.size();
		
		
		while(i<len){
			list.clear();
			while(is_num(a[i])){
				list+=a[i];
				i++;
			}		
			le=str_int(list);
			while(le--){
				cout<<a[i];
			}
			
			i++;
		}
		printf("\n");
	}
	return 0;
}
