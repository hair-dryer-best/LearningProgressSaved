//判断负环 https://www.luogu.com.cn/problem/P3385
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2010;
const int INF = 0x3f3f3f3f;

struct edge
{
  int v, w;
};

int n, m;
vector<edge> e[N];
int d[N];

bool ford(int s)
{
  memset(d, 0x3f, sizeof(d));
  d[s] = 0;
  bool flag;
  for (int i = 1; i <= n; i++)
  {
    flag = false;
    for (int u = 1; u <= n; u++)
    {
      if (d[u] == INF)
        continue;
      for (auto ed : e[u])
      {
        int v = ed.v, w = ed.w;
        if (d[v] > d[u] + w)
        {
          d[v] = d[u] + w;
          flag = true;
        }
      }
    }
    if (!flag)
      break;
  }
  return flag;
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
      e[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
      int u, v, w;
      cin >> u >> v >> w;
      if (w >= 0)
      {
        e[u].push_back({v, w});
        e[v].push_back({u, w});
      }
      else
      {
        e[u].push_back({v, w});
      }
    }
    cout << (ford(1) ? "YES" : "NO") << '\n';
  }
  return 0;
}