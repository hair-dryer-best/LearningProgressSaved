// 洛谷:https://www.luogu.com.cn/problem/P4779
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
vector<pii> e[N];
int dist[N];
bool vis[N];

void dijkstra(int s)
{
  memset(dist, INF, sizeof dist);
  priority_queue<pii, vector<pii>, greater<pii>> que;
  dist[s] = 0;
  que.push({0, s});
  while (que.size())
  {
    int u = que.top().second;
    que.pop();
    if (vis[u])
    {
      continue;
    }
    vis[u] = 1;
    for (auto [to, val] : e[u])
    {
      if (dist[to] > dist[u] + val)
      {
        dist[to] = dist[u] + val;
        que.push({dist[to], to});
      }
    }
  }
}

signed main()
{
  IOS;
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++)
  {
    int from, to, val;
    cin >> from >> to >> val;
    e[from].push_back({to, val});
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++)
  {
    cout << dist[i] << " ";
  }

  return 0;
}