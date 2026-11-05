  ## **指定规则下的排序**:sort/stable_sort

一般来说，cmp默认是有两个参数（依次为x,y）的函数。如果我们希望x能够排在y前面，那么这
个函数就返回1，否则这个函数就返回0。

1．基本用法：左闭右开，默认升序
```cpp
#include <algorithm>
#include <functional>  // greater
#include <vector>
#include <string>
using namespace std;
```
```cpp
sort(a, a + n);                  // 排 a[0] ~ a[n-1]
sort(v.begin(), v.end());        // 排整个 vector
sort(v.begin() + l, v.begin() + r + 1);
```
2．降序：`greater<int>()` 和 `greater<long long>()`
```cpp
int a[1000];
long long b[1000];
sort(a, a + n, greater<int>());
sort(b, b + n, greater<long long>());
```
- 末尾的 **`()` 不能漏**：传入的是 `greater<int>()`，不是 `greater<int>`。
- **可以使用`greater<Student>()` 这样自定义的结构体**，但是要有`booloperator>`函数而非booloperator<

3．手写 `cmp`：

```cpp
struct Student {
    string name;
    int score;
    int id;
};
bool cmp(const Student& a, const Student& b) {
    if (a.score != b.score)
        return a.score > b.score;

    if (a.name != b.name)
        return a.name < b.name;

    return a.id < b.id;
}
sort(stu, stu + n, cmp);  // 注意：写 cmp，不写 cmp()
```
**排序要求比较规则满足“严格弱序”。**

- `cmp(a, a)` 必须为 `false`。
- `cmp(a, b)` 为 `true` 时，`cmp(b, a)` 必须为 `false`。


5．结构体中的 `bool operator<` 

```cpp
struct Student {
    string name;
    int score;
    int id;

    bool operator<(const Student& b) const {
        if (score != b.score)
            return score > b.score;
        if (name != b.name)
            return name < b.name;
        return id < b.id;
    }
};
sort(stu, stu + n);  // 不需要额外传 cmp
```

```cpp
bool operator<(const Student& b) const
```
**整行作为固定模板记住。**

6．另外三种考试常见情况
- **字符串：默认按字典序**
```cpp
string s[1000];
sort(s, s + n);  // 整个字符串按字典序排列
```

若字段是 `char name[100]`，比较内容要用 `strcmp(a.name, b.name) < 0`，不能直接写 `a.name < b.name`；考试中用 `string` 更省事。

- **`pair`：默认先比 `first`，相同再比 `second`，都按升序。**
```cpp
vector<pair<int, int>> v;
sort(v.begin(), v.end());
```

- 要求**稳定排序**：用 `stable_sort`。**
```cpp
bool cmpScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

stable_sort(stu, stu + n, cmpScore);
```


## **找出最大的两个数**
    - 直接从大到小sort（n较大时不好）
    - 手写扫描
    - nth_element 
  `nth_element` 会原地重新排列数组，让你指定位置的元素就位，并按它把数组分成两部分。但它只完成了部分排序，没有保证两边各自有序

```cpp
// 按从大到小的排名，把第 k 大的数放到下标 k - 1 的位置
//k-1及其左边的元素构成前k大的元素，但内部未必有序
    nth_element(a.begin(), a.begin() + k - 1, a.end(), greater<int>());
```
**nth_element也可以把greater<T>()或者cmp作为第四个参数输入**