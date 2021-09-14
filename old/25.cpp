#include <vector>
#include <iostream>
using namespace std;

/*
0811 解説見ながらok
*/

int w,h;
void dfs(vector<vector<int> > &map,int x, int y){

    map[x][y] = 0;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i >= 0 && i < h && j >= 0 &&  j < w){
                if(map[i][j] == 0) continue; 
                dfs(map,i,j);
            }
        }
    }
}
int main(){
    while(true){
        

        int ans = 0;
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        vector<vector<int> > map(h,vector<int>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j] == 0) continue;
                dfs(map,i,j);
                ans++;
            }
        }

        cout << ans << endl;



    }

    return 0;
}