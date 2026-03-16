/*
题目：最大乘积（OIP2000 提高组）

题目描述：
今年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国著名数学家华罗庚先生诞辰90周年。
在华罗庚先生的家乡江苏金坛，组织了一场别开生面的数学智力竞赛的活动，你的一个好朋友XZ也有幸得以参加。
活动中，主持人给所有参加活动的选手出了这样一道题目：

设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，
使得这K+1个部分的乘积能够为最大。

同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：
有一个数字串：312，当N=3,K=1时会有以下两种分法：
3×12=36
31×2=62
这时，符合题目要求的结果是：31×2=62。

现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。

输入格式：
第一行有两个整数N和K，分别表示数字串的长度和乘号的个数。
第二行是一个长度为N的数字串（只包含0-9的数字）。

输出格式：
输出一个整数，表示最大的乘积。

解题思路总结：
这是一道典型的区间动态规划问题。核心思路是将长度为N的数字串插入K个乘号，使乘积最大化。
我们定义dp[i][k]表示前i个数字中插入k个乘号所能得到的最大乘积。状态转移时，考虑最后一个乘号的位置：
假设最后一个乘号放在第j个数字之后（即前j个数字用k-1个乘号，后面一段是j+1到i的数字），
则dp[i][k] = max(dp[j][k-1] × num(j+1, i))，其中num(j+1,i)表示从第j+1位到第i位组成的数字。
初始化时，dp[i][0]就是前i个数字本身的值。最终答案即为dp[N][K]。
由于数字串可能很长，乘积可能超过内置整数范围，需要借助高精度计算。
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct BigInt {
    vector<int> d;
    BigInt() {}
    BigInt(long long x) {
        if (x == 0) d.push_back(0);
        while (x) { d.push_back(x % 10); x /= 10; }
    }
    BigInt(const string& s) {
        for (int i = s.length() - 1; i >= 0; i--) d.push_back(s[i] - '0');
    }
    BigInt operator*(const BigInt& b) const {
        BigInt res;
        res.d.resize(d.size() + b.d.size(), 0);
        for (int i = 0; i < d.size(); i++)
            for (int j = 0; j < b.d.size(); j++) {
                res.d[i + j] += d[i] * b.d[j];
                if (res.d[i + j] >= 10) {
                    res.d[i + j + 1] += res.d[i + j] / 10;
                    res.d[i + j] %= 10;
                }
            }
        while (res.d.size() > 1 && res.d.back() == 0) res.d.pop_back();
        return res;
    }
    bool operator<(const BigInt& b) const {
        if (d.size() != b.d.size()) return d.size() < b.d.size();
        for (int i = d.size() - 1; i >= 0; i--)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
};

ostream& operator<<(ostream& out, const BigInt& x) {
    for (int i = x.d.size() - 1; i >= 0; i--) out << x.d[i];
    return out;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<BigInt>> dp(n + 1, vector<BigInt>(k + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i - 1, k); j++) {
            if (j == 0) {
                dp[i][j] = BigInt(s.substr(0, i));
            } else {
                BigInt mmax;
                bool first = true;
                for (int x = i - 1; x >= 1; x--) {
                    if (x < j) break;
                    BigInt cur = dp[x][j - 1] * BigInt(s.substr(x, i - x));
                    if (first) {
                        mmax = cur;
                        first = false;
                    } else if (mmax < cur) {
                        mmax = cur;
                    }
                }
                dp[i][j] = mmax;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}