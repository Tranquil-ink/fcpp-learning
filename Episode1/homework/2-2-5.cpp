// 题目描述
// 给定一个 row 行 col 列的二维正整数数组 a，要求从 a[0][0] 元素开始，按回形从外向内顺时针顺序遍历整个数组，如图所示


// 关于输入
// 输入的第一行上有两个整数，依次为 row 和 col。
// 余下有 row 行，每行包含 col 个正整数。
// 输入的 row 和 col 保证 1 ≤ row ≤ 100, 1 ≤ col ≤ 100。

// 关于输出
// 按遍历顺序输出每个整数，每个占一行。

// 例子输入
// 4 4
// 1 2 3 4
// 12 13 14 5
// 11 16 15 6
// 10 9 8 7
// 例子输出
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13
// 14
// 15
// 16


#include <iostream>
#include <vector>
#include <string>
using namespace std;

// enum class  up,down,right,left 4cases
//一个tf矩阵
//接收：auto& arr 作为引用来传入，可以更改; cout对应值，并且修改tf矩阵和参数。

enum class Direction {Up, Down, Left, Right};

void circular(vector<vector<int>>& arr, vector<vector<bool>>& tf, Direction& d, int& i, int& j){
    switch(d){
        case Direction::Up:
            cout <<arr[i][j] <<'\n'; 
            tf[i][j] = false;
            if(((i-1)>=0)&&tf[i-1][j]==true) i = i-1;
            else {j = j+1; d = Direction::Right;}
            // cout <<arr[i][j];
            break;
        case Direction::Down:
            cout <<arr[i][j]<<'\n'; 
            tf[i][j] = false;
            if(((i+1)<arr.size())&&tf[i+1][j]==true) i = i+1;
            else {j = j-1; d = Direction::Left;}
            // cout <<arr[i][j];
            break;
        case Direction::Left:
            cout <<arr[i][j]<<'\n'; 
            tf[i][j] = false;
            if(((j-1)>=0)&&tf[i][j-1]==true) j = j-1;
            else {i = i-1; d = Direction::Up;}
            // cout <<arr[i][j];
            break;
        case Direction::Right:
            cout <<arr[i][j]<<'\n'; 
            tf[i][j] = false;
            if(((j+1)<arr[1].size())&&tf[i][j+1]==true) j = j+1;
            else {i = i+1; d = Direction::Down;}
            break;
                  

    }
}



int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j ++){
            cin >> arr[i][j];
        }
    }
    vector<vector<bool>> tf(row, vector<bool>(col, true));
    int posx = 0;
    int posy = 0;
    int count = 0;
    Direction d = Direction::Right;
    while(count < row*col){
        circular(arr, tf, d, posx, posy);
        count +=1;
    }


    return 0;
}