#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
0731 解説見ながらok

最後の精度がわからない

*/

long double dis(vector<vector<double> > &point,int from,int to){

    long double x = point[from][0] - point[to][0];
    long double y = point[from][1] - point[to][1];
    long double ans = pow(x*x + y*y,0.5);
    return ans;
}

int main(){
    int N;
    cin >> N;
    vector<vector<double> > point(N,vector<double>(2));

    for(int i=0;i < N; i++){
        cin >> point[i][0] >> point[i][1];
    }

    vector<int> Node(N);
    for(int i=0;i<N;i++){
        Node[i] = i;
    }

    long double sum = 0.00;
    double size = 0;
    do{
        size++;
        for(int i=0;i<N-1;i++){
            sum += dis(point,Node[i],Node[i+1]);
        }
    }while(next_permutation(Node.begin(),Node.end()));
    long double ans = sum / size;
    cout << ans << endl;
}