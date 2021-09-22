#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    int p[n];
    int q[n];
    int index[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        index[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }

    int p_index;
    int q_index;
    int count = 0;
    do{
        int p_sum = 0;
        int q_sum = 0;
        for(int i = 0; i < n; i++){
            if(index[i] == p[i]){
                p_sum++;
            }
            if(index[i] == q[i]){
                q_sum++;
            }
        }
        if(p_sum == n) p_index = count; 
        if(q_sum == n) q_index = count;
        count++;
    }while(next_permutation(index,index+n));


    cout << abs(p_index - q_index) << endl;

}