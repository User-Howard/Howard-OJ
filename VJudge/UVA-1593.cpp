#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    int ml;
    string line, word;
    vector<vector<string> > T;
    while(getline(cin, line) && line != ""){
        T.push_back(vector<string>());
        stringstream ss(line);
        int pointer = 0;
        while(ss >> word)
            (prev(T.end())) -> push_back(word);
        ml = max(ml, (int)(prev(T.end()))->size());
    }
    /*for(int i = 0;i < T.size();++i){
        for(int j = 0;j < T[i].size();++j)
            cout << "(" << T[i][j] << ")";
        cout << '\n';
    }*/
    vector<int> maxlen(ml, -1);
    for(int i = 0;i < ml;++i)
        for(int j = 0;j < T.size();++j)
            if(i < T[j].size())
                maxlen[i] = max(maxlen[i], (int)T[j][i].size());
        
    
    for(int i = 0;i < T.size();++i){
        for(int j = 0;j < T[i].size();++j){
            int spaces = maxlen[j] - T[i][j].size() + (j!=T[i].size()-1 ? 1 : 0);
            cout << T[i][j];
            while(spaces--)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}