#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> map(1005,vector<bool>(1005,false));
vector<vector<bool>> map2(1005,vector<bool>(1005,false));
vector<vector<int>> val(1005,vector<int>(1005,0));
vector<vector<int>> val2(1005,vector<int>(1005,0));

queue<pair<int,int>> dst;
int s_x,s_y;
int ans = 0;

void bfs(vector<vector<bool>> &map2, int x, int y, int sum, int g_x, int g_y){


    map2[y][x] = false;
    val2[y][x] = sum;

    if(x == g_x && y == g_y){
        s_x = g_x;
        s_y = g_y;
        ans += sum;
    }

    if(map2[y][x+1]){
        bfs(map2,x+1,y,sum+1,g_x,g_y);
    }
    if(map2[y][x-1]){
        bfs(map2,x-1,y,sum+1,g_x,g_y);
    }
    if(map2[y+1][x]){
        bfs(map2,x,y+1,sum+1,g_x,g_y);
    }
    if(map2[y-1][x]){
        bfs(map2,x,y-1,sum+1,g_x,g_y);
    }
}

int main(){
    int H,W,N;
    cin >> H >> W >> N;


    for(int i = 1; i <= H; i++){
        string str;
        cin >> str;
        for(int j = 1; j <=W; j++){
            if(str[i] == 'X'){
                map[i][j] = true;
            }else if(str[i] <= 9 || str[i] >= 0){
                map[i][j] = true;
                pair<int,int> p;
                p.first = j;
                p.second = i;
                dst.push(p);
            }else if(str[i] == 'S'){
                map[i][j] = true;
                s_x = j;
                s_y = i;
            }
        }
    }
    map2 = map;
    val2 = val;


    while(!dst.empty()){
        pair<int,int> p;
        p = dst.front();
        dst.pop();
        bfs(map2,s_x,s_y,0,p.first,p.second);
    }
}