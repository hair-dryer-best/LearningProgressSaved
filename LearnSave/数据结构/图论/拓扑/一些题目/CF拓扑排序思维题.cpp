// 拓扑排序思维题
// https://codeforces.com/contest/2143/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1050500;
int n, in[N], p[N];

vector<int> e[N];

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      in[i] = 0, e[i].clear();
    for (int i = 1; i < n; ++i)

    {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      // 题目分析，转化为小的连大的 的有向图
      if (y < x)
        e[v].push_back(u), ++in[u];
      else
        e[u].push_back(v), ++in[v];
    }
    // 666 其实是拓扑排序
    queue<int> q;
    int cur = 0;
    for (int i = 1; i <= n; ++i)
      if (!in[i])
        q.push(i);

    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      p[u] = ++cur;
      for (auto v : e[u])
      {
        --in[v];
        if (!in[v])
          q.push(v);
      }
    }
    for (int i = 1; i <= n; ++i)
      cout << p[i] << " ";
    cout << "\n";
  }
}