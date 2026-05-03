#include<iostream>
using namespace std;
#include<string>
#include<vector>
const int MAXN=1000005;
struct Node
{
    int len;
    int link;
    int next[26];
} st[MAXN*2];

int sz;
int last;
int cnt[MAXN*2];
void sam_init()
{
    st[0].len=0;
    st[0].link=-1;
    for(int i=0;i<26;i++)
    {
        st[0].next[i]=-1;
        sz=1;
        last=0;
    }
}
void sam_extend(int c) {
    int cur = sz++;          // 1. 创建新状态 cur，代表加入新字符后的整个长串
    st[cur].len = st[last].len + 1;
    for (int i = 0; i < 26; i++) st[cur].next[i] = -1; // 初始化新节点
    
    // 我们给这个新状态记上数。因为新加入一个字符，必然产生一个新的长子串。
    // 这里初始为 1，代表这个状态目前在字符串末尾出现了一次。
    cnt[cur] = 1; 

    int p = last;
    // 2. 沿着旧末尾的“撤退路线”往回走
    // 如果某个状态没有字符 c 的路，就给它加上指向 cur 的路
    while (p != -1 && st[p].next[c] == -1) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        // 情况 A：回到了最顶端也没发现重复，新状态的撤退路线直接连到根
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        // 情况 B：发现已经有一条字符 c 的路通往状态 q
        if (st[p].len + 1 == st[q].len) {
            // 如果 q 刚好紧跟在 p 后面，撤退路线直接连到 q
            st[cur].link = q;
        } else {
            // 情况 C：q 太长了（代表了更多不属于当前后缀的串），需要“裂变” q
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            for (int i = 0; i < 26; i++) st[clone].next[i] = st[q].next[i];
            st[clone].link = st[q].link;
            
            // 裂变出的 clone 节点是一个“虚”状态，它的出现次数初始设为 0
            // 它只是为了让 cur 和 q 有个共同的“撤退点”
            cnt[clone] = 0; 

            // 把所有原来指向 q 的路，改向指向 clone
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            // q 和 cur 的撤退路线现在都统一指向这个 clone
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur; // 更新末尾指针，为下一个字符做准备
}

