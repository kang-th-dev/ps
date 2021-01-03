#include <iostream>
using namespace std;
int matrix[1001][1001];
bool visit[1001][1001]= {false,};
int size;
void euler_circuit(int v){
    for(int i=0; i <= size; i++){
            if(matrix[v][i] != 0 ){
                matrix[v][i] --;
                matrix[i][v] --;
                euler_circuit(i);
            }
    }
    cout << v <<" ";
}

int main(){
    cin >> size;
    for(int i=1; i <= size; i++){
        for(int j=1; j <= size; j++){
            cin >> matrix[i][j];
        }
    }

    bool isEuler = true;
    for(int i=1; i<=size;i++){
        int cnt = 0;
        for(int j=1; j<=size;j++){
            if(matrix[i][j] !=0)
            cnt += matrix[i][j];
        }
        if(cnt %2 !=0){
            isEuler = false;
            break;
        }
    }
    if(isEuler){
        euler_circuit(1);
        cout <<endl;
    }else{
        cout << "-1" <<endl;
    }
}