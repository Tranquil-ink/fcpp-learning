# 端点调试的方法；输入输出法

# 开考前提前写好常用的代码块

# 代码习惯：
- 每个模块前注释一下
- 先写部分代码骨架，待实现部分先注释掉

- 模块化解耦代码，封装函数

- 变量名最好要说清它代表什么：cnt、sum、age 一眼能懂，像a1、b2很容易搞错。
- 缩进需要统一，否则容易弄错括号的层级。
- **数组的全局上界**写成const int MAXN = 1005，而不是a[1005],b[1005],c[1005]，以防打错   
**循环的上界**也建议写成全局的常量。

- 在写搜索/模拟等算法时，判断顺序固定为：**先判断坐标合法，再访问数组，再判断是否属于本次要搜的区域、是否访问过。** 不要先计算 `a[nx][ny]` 再检查越界。（例：魔王军队、菌落数量）

# 快捷键
- **shift+alt+f** 一键排版代码
- **shift+alt+a** 注释一块代码

# 常用代码块
### 把数组开在全局，在main里再设定大小
```cpp
vector<vector<int>> v;
int main(){
    int n,m;
    cin >>n>>m;
    v.resize(n, vector<int>(m)); //将新增的元素初始化为0
}
int main(){ //若有多组测试数据
    int T; cin >>T;
    while (T--){
        int n, m; cin >>n>>m;
        v.resize(n, vector<int>(m, 0)); //重新构造整个数组，手动初始化为0
    }
}
```
### 忽略前0；从最后一个，开始看
```cpp
    int index = 0;

    while(sum[index]==0&&index<sum.size()-1){
        index ++;
    }
    for (int i = index; i < sum.size(); i++){
        cout << sum[i];
    }
```
### 输出矩阵
```cpp
for (int i =0;i<n;i++){
    for(int j=0;j<m;j++){
        cout << v[i][j];
        cout << (j==m-1 ? '\n' : ' ');
    }
}
```


    v.resize(n, string(l,'0'));

## 复杂输入 3-3-6
多行，每行一个用空格分割的后缀表达式。保证表达式长度不超过1000个字符。
表达式中可能出现整数，+ - * /四种运算符，以及@。
```cpp
int main() {
    string line;
    while(getline(cin,line)){
        istringstream iss(line);
        string token;
        stack<long long> st{};
        bool bad = false;
        while(iss>>token && token!="@"){
        //...
        }
        cout << (bad==true ? "NaN" : to_string(st.top())) << endl;
    }
    return 0;
}
```