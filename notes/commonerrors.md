## 2-5-7 EO
倒着循环, i--不要写错

## 2-5-8 WA
注意输入的类型，vector<int> 还是vector<char>不要搞错； 
## 2-5-8 CE expected unqualified-id
多写一个}导致IDE以为main函数结束了

## 2-5-4 WA 多加括号
注意逻辑判断`(A||B&&C) != ((A||B)&&C)`

## 结果不可理喻时，最常见的情况是`if(a == b)`写成`if(a=b)`
## 找不到错误，考虑数据类型溢出：大数据时int应改为long long


## 2-1-4 数组中最长连续相同元素个数
**下标和区间：需要根据“访问了什么”推导循环范围**
```cpp
int frep(vector<int> v){
    int count = 1;
    int count_max = 1;
    for (int i = 0; i < v.size()**-1**; i++){     //循环中设计v[i+1]，因此边界应设在倒数第二个元素
        if (v[i+1] == v[i]){
            count +=1;
        }
        if (v[i+1]!=v[i] || **i+1 == v.size()-1**) {    // 特别若最长连续段在数组末尾怎么处理
            if (count_max < count) count_max = count;
            count = 1;
        }
    }
    return (count_max);
}

```

## !!!遍历(auto a : v)是复制。
**若要修改变量，则要引用传入`for(auto a : v)`**

## 怎么表示`'`
`char c = '\''`

## 单组测试正确，放在多组里错误？
注意每轮输入数组是否清空
```cpp
vector<int> v{};
while(cin...){/*alter v*/}
//典型错误：新建v应放在while内，或者每轮清空
```
## STRUCT 注意命名要首字母大写

## 3-4-2 注意上述函数适用限制
关于输入
一行两个非负整数，非负整数s（s ≦ 10^9）和乘号的个数k（0 ≦ k < s的位数）。
输入保证，如果按题目要求的乘法操作，不会使int发生溢出。

关于输出
一行一个整数，即乘积的最大值 

- 构造函数递归`long long maxproduct(string s, long long k){}`  
遗漏情况：
    - 结束条件有2个 `if (s.length()==1 || k==0) return stoll(s);`
    - 枚举`maxproduct(sub1, k-1) * stoll(sub2)`的时候，注意上述函数适用限制:`if ((k-1) >= s1.length()) continue;`


## 只运行几ms却timeout：很可能是第一个n忘记cin

## 复制一段代码，一定检查变量名是不是全改了

## 不要忘记cin.ignore()
## 多组数据没有终止符号：不要用`while(true)` 用`while (cin >> n >> m)`
while(true) 读入多组数据，但没有判断 cin >> n >> m 是否成功，遇到 EOF 会死循环。

### 4-2-7 二维数组递推，求花费最少路径
- 将从每个点开始的最小花费存在一个二维数组cost中，减少重复计算   
  *想到了，但是在函数返回前忘记要存这个cost*

### for循环，i在循环外定义,结束时i==n
```cpp
int i;
for (i = 0; i < n; ++i) {}
```


## 提交前检查是不是多组数据
### 详情各种情况，不要被样例局限
“子矩阵”不一定是方阵


输出一个数组中最后一个使前i项和小于m的是第几项
```cpp
    int sumprice = 0;
    int i;
    for (i = 0; i < v.size(); i++){
        sumprice+=v[i].p;
        if (sumprice>m) break;
    }
    if (sumprice>m) i--;
    cout << i+1;

    int sumprice = 0;
    int i;
    while(i < v.size() && sumprice<=m){
        sumprice+=v[i].p;
        i++;
    }
    if (sumprice>m) i--;
    cout << i;
```

## 多重循环时，注意循环内数组下标不要写错 i还是j？

## RTE
检查输入输出有没有问题，比如iss>>token写成cin
## switch case 一定要加break，否则一次进行到底