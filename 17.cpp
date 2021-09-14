#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int> > grid(8,vector<int>(8,0));

    for(int i=0; i < N; i++){
        int x,y;
        cin >> x >> y;
        for(int j=0;j < 8; j++) grid[x][j] = 1;
        for(int j=0;j < 8; j++) grid[j][y] = 1;
        
        int t = 0;
        while(x+t < 8 && y+t < 8){
            grid[x+t][y+t] = 1;
            t++;
        }
        t=0;
        while(x+t < 8 && y-t  >= 0){
            grid[x+t][y-t] = 1;
            t++;
        }
        t=0;
        while(x-t >= 0 && y+t < 8){
            grid[x-t][y+t] = 1;
            t++;
        }
        t=0;
        while(x-t >= 0 && y-t >= 0){
            grid[x-t][y-t] = 1;
            t++;
        }
    
    
    }

    for(int i=0; i < 8; i++){
        for(int j=0; j < 8; j++){
            if(grid[j][i] == 1){
                cout << "." ;
            }else{
                cout << "Q";
            }
        }
        cout << endl;
    }
}