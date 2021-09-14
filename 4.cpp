/*
全探索

0729 ok
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int> > point(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> point[i][j];
        }
    }

    long long int sum = 0;
    long long int max = 0;
    for(int k=0;k<M-1;k++){
        for(int l=k+1;l<M;l++){
            sum = 0;
            for(int m=0;m<N;m++){
                if(point[m][k]>point[m][l]){
                    sum += point[m][k];
                }else{
                    sum += point[m][l];
                }
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    cout << max << endl;


}