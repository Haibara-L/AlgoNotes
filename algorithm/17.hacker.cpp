#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

// 快速幂：用于计算乘法逆元
ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

// 预处理阶乘数组，防止在循环内重复计算导致超时
ll fact[1000005]; 

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    // 预计算阶乘
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<int> v(n);
    map<int, int> data;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        data[v[i]]++;
    }

    ll totalnum = 0;
    // 使用 long long 防止 i*i 溢出
    for (ll i = 1; i * i <= n - 2; i++) {
        if ((n - 2) % i == 0) {
            ll j = (n - 2) / i;
            
            // 检查 i 和 j 是否都在原序列中
            if (data.count(i) && data.count(j)) {
                // 特殊情况：如果 i == j，要求该数字至少出现 2 次
                if (i == j && data[i] < 2) continue;

                // 复制一份统计数据，用于扣除作为 n, m 的那两个数
                map<int, int> tempdata = data;
                tempdata[i]--;
                tempdata[j]--;

                // --- 核心取模逻辑修改 ---
                // 分子是 (n-2)!
                ll numerator = fact[n - 2];
                
                // 分母是所有剩余数字出现次数阶乘的乘积
                ll denominator = 1;
                for (auto const& [val, count] : tempdata) {
                    if (count > 0) {
                        denominator = (denominator * fact[count]) % MOD;
                    }
                }

                // 使用逆元处理除法：num = numerator / denominator % MOD
                ll num = (numerator * power(denominator, MOD - 2)) % MOD;

                // 如果 i != j，说明 (n,m) 和 (m,n) 是两种情况，结果 * 2
                if (i != j) {
                    num = (num * 2) % MOD;
                }
                
                totalnum = (totalnum + num) % MOD;
            }
        }
    }

    cout << totalnum << endl;
    return 0;
}