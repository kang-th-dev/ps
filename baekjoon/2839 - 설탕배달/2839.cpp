#include <iostream>
using namespace std;
int s1 = 5;
int s2 = 3;
int main(){
    int N;
    cin >> N;
    int x=0,y=0;
    while(1){
        if((s1 * x) + (s2 *y) > N){
            x=0;
            y++;
            continue;
        }else if((s1 * x) + (s2 *y) == N){
            cout << x+y<<endl;
            return 0;
        }
        if(x+y >= N){
            cout << "-1"<<endl;
            return 0;
        }


        x++;

    }
}