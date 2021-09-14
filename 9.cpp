#include <iostream>
#include <vector>
using namespace std;

/*
0730 no

*/
int main(){
    int N,M;
    cin >> N;

    vector<vector<int> > star(1000001,vector<int>(1000001));
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        star[x].push_back(y);
    } 

    cin >> M;
    // vector<vector<int> > list(M,vector<int>(2));
    vector<vector<int> > list(1000001,vector<int>(1000001));
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        list[x].push_back(y);
    // cin >> list[i][0] >> list[i][1];
    }

    cout << star[2].size() << endl;

}