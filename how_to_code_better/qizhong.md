可能有很大的输出，一定用long long



## 06
自然产生贪心的思路，从左往右依次找v,i,k,a，找到一个找下一个
*符合自然思考过程，不要一味追求“一次解决”*
```cpp
int i = 0;
while (i < n){ // 假设有n列
    if (第i列有v) break;
    i++;
}   
```


## 08
数组初始化，设-1作为标识符
```cpp
// 开一个长30的vector<int>,初始化为-1
// 写一个函数
void tolower


for(i遍历字符串){
    if (是小写字母‘a'+k && v[i]==-1)  v[i] = k ;   
}
a'+i

```

## 09
如果对排序稳定性有要求，就要手写冒泡，不能用sort（快速排序，不稳定）
可以用stable_sort
冒泡排序的交换次数即为逆序对个数（交换相邻，逆序对数-1）


## 10
维持一个偏移量数组
```cpp
char c;
string s{};
vector<string> v{};
int countblank = 0;
while(cin >>c){
    if (c == ' '){
        if (!s.empty()) v.push_back(s);
        countblank ++;
        s = "";
    }
    else {
        s = s + c;
    }
}
cout << v[0];
if (v.size() == 1){//处理只有一个单词的特殊情况
    string allblank(countblank, ' ');
    cout << allblank;
    return 1;
} 
int blanklength = countblank / (v.size()-1);
string blanks(blanklength, ' ');
int blankleft = countblank % (v.size()-1);
string endblanks (blankleft, ' ');
for (int i = 1; i < v.size()) cout << blanks << v[i];
cout << endblanks;
return 0;
```



## 12 单调栈思想
通过复杂度推算思路
普通n2不行？
能不能从左到右扫描一遍就实现？
```cpp

```

## 15
n项序列，每一项从m个元素里选择。求最小的k，使得存在一个k项序列（每一项也从这m个元素里选），它不是原序列的子列。  
*算法：* 
从左到右扫描，⽤数组记录当前段已经⻅过哪些⾳符。每当累计⻅到全部 M 种⾳符，就⽴刻结束这⼀段并开始
下⼀段。设⼀共得到 k 个完整段，则答案为 k+1；末尾不完整的部分不计⼊ k。
*正确性* 关键是证明存在长k+1且非子列的序列  
此处思想类似`06`中找vika。构造一个序列c，c1~ck为1~k段的最后一个元素，c(k+1)为k+1段没有出现的元素。
用贪心法找序列c(第一次出现就选中)，c_i一定在第i段末第一次出现(i=1~k)，进而不存在。
*实现*
```cpp
vector<int> seen(10001, 0);  
int round = 1, kinds = 0， /*blocks=0*/;
for (int i=0;i<n;i++){
    int x;
    cin>>x;
    if(seen[x]!=round){
        seen[x]=round;
        kinds+=1;
    }
    if (kinds==m){
        round++;
        //blocks++；
        kinds=0;
    }
}
//最终完整的段数为round-1；
//可以通过再维护一个blocks来记录，以免搞错
```

## 16

**在循环中动态找最小值：用-1来初始化变量**
```cpp
long long mincost = -1;
int location = 0;
for(int i = 0;i<n;i++>){
    long long cost = 0;
    // 计算得到这个情况的cost
    if (mincost==-1||cost<mincost){  //合并处理初始情况
        mincost = cost;
        location = i;
    }
}
```


