#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            cin >> arr[i][j];
        }
    }
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            if (arr[i][j] <= 50){
                c1+=1;
                if (i == 0||i==N-1||j == 0||j==N-1){
                    c2+=1;
                }
                else if(arr[i-1][j] >50 ||arr[i+1][j] >50 ||arr[i][j-1] >50 ||arr[i][j+1] >50 ) c2+=1;
            }

        }
    }
    cout << c1 << ' ' << c2;

    return 0;
}