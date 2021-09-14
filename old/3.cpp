#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;

/*
0728 ok
文字列処理を参考にする
*/

bool judge(string t){
    string s[4] = {"A","C","G","T"};

    for(int i=0;i<4;i++){
        if(s[i].compare(t) == 0){
            return true;
        }
    }
    return false;
}


int main(){

    string t;
    cin >> t;

    int max = 0;
    int sum = 0;
    for(int i=0;i<t.size();i++){
        string l = t.substr(i,1);
        if( judge(l) ){
            sum++;
        }else{
            if(sum > max){
                max = sum;
            }
            sum = 0;
        }
    }
    if(sum > max) max = sum;
    cout << max << endl;
}