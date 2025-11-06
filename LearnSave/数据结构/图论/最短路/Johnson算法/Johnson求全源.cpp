#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const ll INF = 1e9;
const int N = 3005;
int n, m;
struct node
{
  int to;
  int val;
};
vector<node> e[N];
int d[N], h[N];
int cnt[N];
bool vis[N];
bool spfa();
void dijkstra(int s);
signed main()
{
  IOS;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }
  for (int i = 1; i <= n; i++)
  {
    e[0].push_back({i, 0});//虚拟0点
  }
  if (!spfa())
  {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; i++)
  {
    for (auto &ed : e[i])
    {
      ed.val += h[i] - h[ed.to];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    dijkstra(i);
    ll ans = 0;
    for (int j = 1; j <= n; j++)
    {
      if (d[j] == INF)
      {
        ans += INF * (ll)j;
      }
      else
      {
        ans += (ll)j * (d[j] + h[j] - h[i]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

bool spfa()
{
  queue<int> q;
  memset(h, 63, sizeof h);
  memset(vis, 0, sizeof vis);
  h[0] = 0, vis[0] = 1, q.push(0);
  while (q.size())
  {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (auto ed : e[u])
    {
      int v = ed.to, w = ed.val;
      if (h[v] > h[u] + w)
      {
        h[v] = h[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] > n)
        {
          return 0;
        }
        if (!vis[v])
        {
          vis[v] = 0, q.push(v);
        }
      }
    }
  }
  return 1;
}
void dijkstra(int s)
{
  for (int i = 0; i <= n; i++)
  {
    d[i] = INF;
  }
  memset(vis, 0, sizeof vis);
  priority_queue<pli, vector<pli>, greater<>> que;
  d[s] = 0;
  que.push({0, s});
  while (que.size())
  {
    int from = que.top().second;
    que.pop();
    if (vis[from])
      continue;
    vis[from] = 1;
    for (auto &ed : e[from])
    {
      int v = ed.to;
      int w = ed.val;
      if (d[v] > d[from] + w)
      {
        d[v] = d[from] + w;
        if (!vis[v])
        {
          que.push({d[v], v});
        }
      }
    }
  }
}