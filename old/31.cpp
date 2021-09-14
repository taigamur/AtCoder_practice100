#include <iostream>
#include <queue>
using namespace std;
int map[105][105] = {0};

int main(){
    int w,h;
    cin >> w >> h;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int t;
            cin >> t;
            map[i+1][j+1] = t;
        }
    }

    int sum = 0;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){

            if(map[i+1][j+1] == 1){
                sum++;
                queue<int> que_x;
                queue<int> que_y;
                que_x.push(i+1);
                que_y.push(j+1);
                while(!que_x.empty()){
                    int x = que_x.front();
                    que_x.pop();
                    int y = que_y.front();
                    que_y.pop();
                    
                    if(map[y][x+1] == 1){
                        que_x.push(x+1);
                        que_y.push(y);
                        map()
                    }

                }
                


            }
        }
    }

}