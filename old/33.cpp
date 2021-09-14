#include <iostream>
#include <queue>
using namespace std;

/*
0816  幅優先の基本的な問題

*/

int map[55][55] = {0};
int ans[55][55] = {0};
int main(){
    int h,w;
    cin >> h >> w;
    int sum = 0;
    for(int i=1;i<=h;i++){
        string t;
        cin >> t;
        for(int j=1;j<=w;j++){
            if(t[j-1] == '.'){
                map[i][j] = 1;
            }else{
                sum++;
            }
        }
    }


    queue<int> que_x;
    queue<int> que_y;
    que_x.push(1);
    que_y.push(1);
    ans[1][1] = 1;
    map[1][1] = 0;
    while(!que_x.empty()){
        int x = que_x.front();
        que_x.pop();
        int y = que_y.front();
        que_y.pop();
        
        if(map[y][x+1]==1){
            ans[y][x+1] = ans[y][x] + 1;
            map[y][x+1] = 0;
            que_x.push(x+1);
            que_y.push(y);
        }
        if(map[y][x-1]==1){
            ans[y][x-1] = ans[y][x] + 1;
            map[y][x-1] = 0;
            que_x.push(x-1);
            que_y.push(y);
        }
        if(map[y+1][x]==1){
            ans[y+1][x] = ans[y][x] + 1;
            map[y+1][x] = 0;
            que_x.push(x);
            que_y.push(y+1);
        }
        if(map[y-1][x]==1){
            ans[y-1][x] = ans[y][x] + 1;
            map[y-1][x] = 0;
            que_x.push(x);
            que_y.push(y-1);
        }

    }

    if(ans[h][w] == 0){
        cout << -1 << endl;
    }else{
        cout << h*w - sum - ans[h][w] << endl;
    }
    
}