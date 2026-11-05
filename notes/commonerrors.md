## 2-5-7 EO
倒着循环, i--不要写错

## 2-5-8 WA
注意输入的类型，vector<int> 还是vector<char>不要搞错； 
## 2-5-8 CE expected unqualified-id
多写一个}导致IDE以为main函数结束了

## 2-5-4 WA
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

