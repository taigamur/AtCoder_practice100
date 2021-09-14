#include <iostream>
#include <string.h>
using namespace std;


/*
0812  時間かかったがok
関数での配列の使い方やコピーが勉強になった
コピーの際にconstでないとエラーになる場合がある
*/

const int m_size = 90;

int max_ans = 0;
int ans;
int m,n;

void dfs(int map[m_size][m_size],int x, int y, int ans){

    ans++;
    map[y][x] = 0;
    int map2[m_size][m_size];

    if(x-1 >= 0 && map[y][x-1] == 1){
        memcpy(map2,map,sizeof(map2));
        map2[y][x-1] = 0;
        dfs(map2,x-1,y,ans);
    }
    if(x+1 < m && map[y][x+1] == 1){
        memcpy(map2,map,sizeof(map2));
        map2[y][x+1] = 0;
        dfs(map2,x+1,y,ans);
    }
    if(y-1 >= 0 && map[y-1][x] == 1){
        memcpy(map2,map,sizeof(map2));
        map2[y-1][x] = 0;
        dfs(map2,x,y-1,ans);
    }
    if(y+1 < n && map[y+1][x] == 1){
        memcpy(map2,map,sizeof(map2));
        map2[y+1][x] = 0;
        dfs(map2,x,y+1,ans);
    }

    if(max_ans < ans){
        max_ans = ans;
    }

}


int main(){

    cin >> m;
    cin >> n;
    int map[m_size][m_size];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    int map2[m_size][m_size];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 1){
                ans = 0;
                memcpy(map2,map,sizeof(map));
                dfs(map2,j,i,ans);
                // cout << "-------------" << endl;
                // cout << map[0][0] << " " << map[0][1] << endl;
                // cout << map[1][0] << " " << map[1][1] << endl;
            }
        }
    }
    cout << max_ans << endl;

    return 0;
}