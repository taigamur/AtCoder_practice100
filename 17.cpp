#include <iostream>
#include <vector>
using namespace std;

/*
0921 WA
N-クイーン問題について調べる
*/

vector<vector<bool>> map(8,vector<bool>(8,true));

vector<bool> list(8,true);//trueは可能

void change(int x, int y){
    list[x] = false;
    for(int i = 0; i < 8; i++){
        map[x][i] = false;
    }
    for(int i = 0; i < 8; i++){
        map[i][y] = false;
    }
    for(int i = 0 ; i < 8; i++){
        if(x + i < 8 & y + i < 8){
            map[x+i][y+i] = false;
        }
        if(x + i < 8 & y - i >= 0){
            map[x+i][y-i] = false;
        }
        if(x - i >= 0 & y + i < 8){
            map[x-i][y+i] = false;
        }    
        if(x - i >= 0 & y - i >= 0){
            map[x-i][y-i] = false;
        }

    }
}

int main(){
    int n;
    cin >> n;

    

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        change(x,y);
    }


    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(map[i][j]){
                cout << "Q";
            }else{
                cout << "-";
            }
            
        }
        cout << endl;
    }

    while(sum < 8 - n){

    }
}