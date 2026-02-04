//
// Created by awake on 2026/2/4.
//https://www.luogu.com.cn/problem/P1892
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int fa[MAXN * 2];

int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}

void unite(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 1~n 为本体域，n+1~2n 为敌人域
    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        char opt;
        int p, q;
        cin >> opt >> p >> q;

        if (opt == 'F')
        {
            // p 和 q 是朋友 -> 直接合并本体
            unite(p, q);
            // 朋友的敌人不一定是敌人的朋友所以unite(p + n, q + n);不加
        }
        else if (opt == 'E')
        {
            // p 和 q 是敌人
            // 敌人的敌人是朋友
            unite(p + n, q);
            unite(q + n, p);
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if(find(i) == i)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}