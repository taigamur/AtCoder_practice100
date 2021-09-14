#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
0730 ok
*/

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    vector<int> list(N);

    for(int i=0;i<N; i++) cin >> a[i];
    for(int i=0;i<N; i++) cin >> b[i];
    for(int i=0;i<N; i++) list[i] = i+1;

    int count = 0;
    int ans_a,ans_b;
    do{
        int a_i = 0;
        int b_i = 0;

        for(int i=0;i<N;i++){
            if(list[i] == a[i]) a_i++;
            if(list[i] == b[i]) b_i++;
        }

        if(a_i == N) ans_a = count;
        if(b_i == N) ans_b = count;

        count++;
    }while(next_permutation(list.begin(),list.end()));

    cout << abs(ans_a - ans_b) << endl;
}