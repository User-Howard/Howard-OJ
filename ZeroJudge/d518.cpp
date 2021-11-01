#include <iostream>
#include <unordered_map>
using namespace std;


int main(void){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(cin >> N and N){
        unordered_map<string, int>ump;
        int inputid = 1;
        for(int i=0;i<N;++i){
            string s;
            cin >> s;
            if(ump.find(s)!=ump.end())
                cout << "Old! ";
            else{
                cout << "New! ";
                ump[s] = inputid++;
            }
            cout << ump[s] << '\n';
        }
    }

	return 0;
}
