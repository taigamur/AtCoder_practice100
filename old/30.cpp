#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int size_m = 1005;
int map[size_m][size_m] = {0};

/*
0816 解説見ながらok
*/

int dis(int from_x,int from_y,int to_x,int to_y){

    int map2[size_m][size_m];
    int x = from_x;
    int y = from_y;

    queue<int> que_x;
    queue<int> que_y;
    int ans[size_m][size_m];
    que_x.push(x);
    que_y.push(y);
    map2[y][x] = 0;
    ans[y][x] = 0;

    memcpy(map2,map,sizeof(map));

    while(!que_x.empty()){
        x = que_x.front();
        que_x.pop();
        y = que_y.front();
        que_y.pop();
        
        if(map2[y][x+1] == 1){
            que_x.push(x+1);
            que_y.push(y);
            ans[y][x+1] = ans[y][x]+1;
            map2[y][x+1] = 0;
        }
        if(map2[y][x-1] == 1){
            que_x.push(x-1);
            que_y.push(y);
            ans[y][x-1] = ans[y][x]+1;
            map2[y][x-1] = 0;
        }
        if(map2[y+1][x]){
            que_x.push(x);
            que_y.push(y+1);
            ans[y+1][x] = ans[y][x]+1;
            map2[y+1][x] = 0;
        }
        if(map2[y-1][x]){
            que_x.push(x);
            que_y.push(y-1);
            ans[y-1][x] = ans[y][x]+1;
            map2[y-1][x] = 0;
        }
        

    }

    return ans[to_y][to_x];

}


int main(){
    int h,w,n;
    cin >> h >> w >> n;
    string t;
    int list[n+1][2];
    for(int i=0;i<h;i++){
        cin >> t;
        for(int j=0;j<w;j++){
            if(t[j] == '.'){
                map[i+1][j+1] = 1;
            }else if(t[j] - '0' > 0 && t[j] - '0' <= n ){
                map[i+1][j+1] = 1;
                list[t[j]-'0'][0] = j+1;
                list[t[j]-'0'][1] = i+1;
            }else if(t[j] == 'S'){
                list[0][0] = j+1;
                list[0][1] = i+1;
                map[i+1][j+1] = 1;
            }
        
        }
    }

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += dis(list[i][0],list[i][1],list[i+1][0],list[i+1][1]);
    }

    cout << sum << endl;

}