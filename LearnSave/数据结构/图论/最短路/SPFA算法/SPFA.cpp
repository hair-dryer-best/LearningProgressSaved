// 求负环https://www.luogu.com.cn/problem/P3385#submit
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 2010;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
int n, m;
struct edge
{
  int v;
  int w;
};
vector<edge> e[N];
int d[N];
int cnt[N]; // 记录开始到这个点走过的边的数量
int vis[N]; // 是否在队内

bool spfa(int s);

signed main()
{
  IOS;
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
    if (spfa(1))
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}

bool spfa(int s)
{
  memset(d, INF, sizeof d);
  memset(vis,0,sizeof vis);
  memset(cnt,0,sizeof cnt);
  queue<int> q;
  d[s] = 0;
  vis[s] = 1;
  q.push(s);
  while (q.size())
  {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (auto ed : e[u])
    {
      int v = ed.v, w = ed.w;
      if (d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= n)
          return 1;
        if (!vis[v])
        {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return 0;
}
