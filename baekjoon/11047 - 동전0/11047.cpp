#include <iostream>
using namespace std;
int n_i[11];
int main(){
    int n,k;
    int result = 0;
    cin >>n>>k;
    for(int i=0; i <n; i++){
        cin>>n_i[i];
    }
    for(int i=n-1; i >=0; i--){
        if(n_i[i] <= k ){
            result += k/ n_i[i];
            k %= n_i[i];
        }
        if(k ==0){
            break;
        }
    }
    cout << result;
}