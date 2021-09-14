#include <iostream>
#include <vector>
using namespace std;

//0917 未解決問題　解決

vector<vector<int>> point(N,vector<int>(2));

int dis(int a, int b){
    int a = abs(point[a][0] - point[b][0]);
    int b = abs(point[a][1] - point[b][1]);

    return a*a + b*b;
}

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> point[i][0] >> point[i][1];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int t = dis(i,j);
            for(int k=j+1;k<N;k++){
                if(t == dis(i,k) || t == dis(j,k)){
                    for(int l=k+1;l<N;l++){
                        
                    }
                }
            }


        }
    }


}