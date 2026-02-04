//
// Created by awake on 2026/2/4.
//https://www.luogu.com.cn/problem/P2024
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 50005; // 【修改1】范围由 1000 改为 50005
int fa[N], d[N];

int find(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    int root = find(fa[x]);       // 1. 先保存根节点
    d[x] = (d[x] + d[fa[x]]) % 3; // 2. 更新权值：当前到原父节点 + 原父节点到根
    fa[x] = root;                 // 3. 路径压缩
    return root;
}

// 计算 x 到 y 的相对关系 (d[x] - d[y])
int dist(int x, int y)
{
    return (d[x] - d[y] + 3) % 3;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        d[i] = 0;
    }
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;

        // 题目条件：如果 X 或 Y 比 N 大，是假话
        // 题目隐含条件：如果 op=2 且 X=Y，也是假话（自己吃自己）
        if (x > n || y > n || (op == 2 && x == y))
        {
            cnt++;
            continue;
        }

        int fx = find(x);
        int fy = find(y);

        if (op == 1) // 说法：X 和 Y 是同类
        {
            if (fx == fy)
            {
                // 如果在同一棵树，检查关系是否矛盾
                // 同类意味着 d[x] 和 d[y] 对 3 同余，即差值为 0
                if (dist(x, y) != 0)//x,y在同一颗树且不在同一层，则不是同类，是假话
                    cnt++;
            }
            else
            {
                // 合并：让 x 的根指向 y 的根
                fa[fx] = fy;
                // 关系推导：(d[x] + d[fx]) % 3 == d[y] % 3
                // => d[fx] = d[y] - d[x]
                d[fx] = (d[y] - d[x] + 3) % 3;//x,y应在同一层，到根的距离应相等，d[fx]+d[x]=d[y],d[x]为到fx的距离
            }
        }
        else // 说法：X 吃 Y
        {
            if (fx == fy)
            {
                // X 吃 Y 意味着：(d[x] - d[y]) % 3 == 1
                if (dist(x, y) != 1) //x,y在同一颗树且x不在y的下一层，则不满足x吃y，是假话
                    cnt++;
            }
            else
            {
                // 合并
                fa[fx] = fy;
                // 关系推导：X 吃 Y => (d[x] + d[fx] - d[y]) % 3 == 1
                // => d[fx] = d[y] - d[x] + 1
                d[fx] = (d[y] - d[x] + 1 + 3) % 3;//x应在y的下一层，到根的距离应多1，d[fx]+d[x]=d[y]+1
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    IOS;
    solve();
    return 0;
}
