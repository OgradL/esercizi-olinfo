#include <iostream>
#include <vector>

using namespace std;

int main(){

    string W;
    int N;

    cin >> W >> N;

    int time = 0;
    int speed = 1;
    int tmp = 0;

    string w;

    for (int i = 0; i < N;){
        for (; i < N && tmp > 0; i++, tmp--){
            cin >> w;
            if (w == W){
                speed++;
            }
        }
        time++;
        tmp = speed;
    }
    cout << time - 1 << "\n";

    return 0;
}