//
// Created by awake on 2026/2/4.
//https://www.luogu.com.cn/problem/P2024
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
const int N = 5e4 + 5;
// 扩展域并查集  n+1~2n为捕食关系，2n+1~3n为天敌关系
int fa[N * 3];
int n, k;
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unit(int x, int y)
{
    fa[find(x)] = find(y);
}

void solve()
{
    for (int i = 0; i < N * 3; i++)
    {
        fa[i] = i;
    }

    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            cnt++;
            // cout<<"i="<<i<<endl;
            continue;
        }
        if (op == 1)
        {
            if (find(x) == find(y + n) || find(x) == find(y + 2 * n))
            {
                cnt++;
                // cout<<"i="<<i<<endl;
                continue;
            }
            unit(x, y);
            unit(x + n, y + n);
            unit(x + 2 * n, y + 2 * n);
        }
        else // x吃y
        {
            if (find(x) == find(y) || find(x) == find(y + n))
            {
                cnt++;
                // cout<<"i="<<i<<endl;
                continue;
            }
            unit(x + n, y);
            unit(x + 2 * n, y + n);
            unit(x, y + 2 * n);
        }
    }
    cout << cnt << endl;
}

signed main()
{
    IOS;
    int T;
    T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
