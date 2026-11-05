#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N=5;
    // cin >> N;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            cin >> arr[i][j];
        }
    }
    vector <int> rowmax(N,0);
    vector <int> colmin(N,0);

    for (int i = 0; i < N; i++){
        rowmax[i] = *max_element(arr[i].begin(), arr[i].end());
    }
    for (int j = 0; j < N; j++){
        int min = arr[0][j];
        for (int i = 0; i < N; i++){
            if (arr[i][j] < min) min = arr[i][j];
        }
        colmin[j] = min;
    }
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == rowmax[i] && arr[i][j] == colmin[j]) {cout << i +1<<' ' <<j+1 <<' '<< arr[i][j] <<endl; count +=1;}
        }
    }
    if (count == 0){
        cout << "not found";
    }
    return 0;
}