#include <iostream>
#include <vector>
using namespace std;


/*
0730 no
*/

vector<int> mask;
bool judge(int cnt=0,int s){





    judge(cnt,0);
    judge(cnt,1);

}

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int> > t(M,vector<int>));

    for(int i=0; i < M; i++){
        int s;
        cin >> s;
        for(int j=0; j < s; j++){
            int u;
            cin >> u;
            t[i].push_back(u);
        }
    }

    vector<int> p(M);
    for(int i=0; i < M; i++){
        int s;
        cin >> s;
        p[i] = s;
    }

    make_mask()


}