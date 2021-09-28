#include <vector>
#include <iostream>
using namespace std;

int main(){
    
    vector<vector<int>> map(105,vector<int>(105,0));
    int w,h;
    cin >> w >> h;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            int t;
            cin >> t;
            if(t == 1){
                map[i][j] = t;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            int sum = 0;
            if(map[i][j] == 1){
                if(map[i][j-1]) sum++;
                if(map[i][j+1]) sum++;

                if(y % 2 == 0){
                    if()
                }else{

                }
                ans += sum;
            }
        }
    }

}