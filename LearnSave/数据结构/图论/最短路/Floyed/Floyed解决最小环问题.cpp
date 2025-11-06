// 洛谷最小环问题:https://www.luogu.com.cn/problem/P6175
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const ll INF = 1e8;
const int N = 105;

void solve()
{
  int n, m;
  cin >> n >> m;
  int u, v, d;
  int ans = INF;
  int dist[N][N];
  int w[N][N];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dist[i][j] = INF;
      w[i][j] = INF;
    }
  }

  for (int i = 1; i <= m; i++)
  {
    cin >> u >> v >> d;
    dist[u][v] = dist[v][u] = d;
    w[u][v] = w[v][u] = d;
  }
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i < k; i++)
      for (int j = i + 1; j < k; j++)
        ans = min(ans, dist[i][j] + w[j][k] + w[k][i]);

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  if (ans == INF)
  {
    cout << "No solution.\n";
  }
  else
  {
    cout << ans << "\n";
  }
}
signed main()
{
  IOS;
  int T;
  T = 1;
  while (T--)
  {
    solve();
  }
  return 0;
}