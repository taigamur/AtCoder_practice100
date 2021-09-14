#include <iostream>
#include <string>
using namespace std;

// 0917 未解決問題を解決

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;


    //重複はカウントしないため、手前から見つけた順番で処理して問題ない
    int ans = 0;
    for(int i = 0; i < 10; i++){
        int i_index = s.find(to_string(i));
        if(i_index == -1){
            continue;
        }
        for(int j = 0; j < 10; j++){
            int j_index = s.find(to_string(j), i_index + 1);
            if(j_index == -1){
                continue;;
            }
            for(int k = 0; k < 10; k++){
                int k_index = s.find(to_string(k), j_index + 1);
                if(k_index == -1){
                    continue;
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
}