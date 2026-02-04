//
// Created by awake on 2026/2/4.
//https://www.luogu.com.cn/problem/P1197
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 4e5 + 10;

int fa[N];
bool del[N];
vector<int> que;
vector<int> adj[N];

int f(int x)
{
    return fa[x] == x ? x : fa[x] = f(fa[x]);
}

void solve()
{
    int n, m;
    int k;
    vector<int> ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        que.pb(x);
        del[x] = 1;
    }
    int tot = n - k;
    for (int i = 1; i <= n; i++)
    {
        if (del[i])
            continue;
        for (int j : adj[i])
        {
            if (del[j])
                continue;
            if (f(i) != f(j))
            {
                fa[f(i)] = f(j);
                tot--;
            }
        }
    }
    ans.pb(tot);
    for (int i = k; i >= 1; i--)
    {
        int x = que[i - 1];
        del[x] = 0;
        tot++;
        for (int j : adj[x])
        {
            if (del[j])
                continue;
            if (f(x) != f(j))
            {
                fa[f(x)] = f(j);
                tot--;
            }
        }
        ans.pb(tot);
    }
    reverse(all(ans));
    // cout << "-------------\n";
    for (int i : ans)
    {
        cout << i << "\n";
    }
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