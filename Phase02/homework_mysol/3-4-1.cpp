#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 题目描述
Serling公司购买长钢条，将其切割为短钢条出售。切割工序本身没有成本支出。公司管理层希望知道最佳的切割方案。假定我们知道Serling公司出售一段长为i英寸的钢条的价格为pi(i=1,2,…，单位为美元)。钢条的长度均为整英寸。

给定一段长度为n英寸的钢条和一个价格表pi(i=1,2,…n)，求切割钢条方案，使得销售收益rn最大。

关于输入
第一行：n，表示购买的长钢条的长度。
接下来一行包含 n 个数字，第 i 个数字出售长为 i 的钢条的价格，即 pi。

其中 0 < n <= 3000，0 < pi <= 10000。

关于输出
输出仅一行，为最大的销售收益值 rn。 */

vector<int> dp{};
vector<int> v{};

int main() {
    int n;
    cin>>n;
    dp.resize(n+1);
    v.resize(n+1);
    for(int i =1;i<=n;i++){
        cin>>v[i];
    }
    for(int i =1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],v[i-j]+dp[j]);
        }
    }
    cout<<dp[n]<<endl;


    
    return 0;
}