// https://www.luogu.com.cn/problem/P1656
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 3000;

vector<pair<int, int>> e;
vector<int> h[N];
struct bridge
{
  int x, y;
  bool operator<(const bridge &t) const
  {
    if (x == t.x)
      return y < t.y;
    return x < t.x;
  }
};
vector<bridge> bri;
int dfn[N], low[N], tim;

void add(int a, int b)
{
  e.push_back({a, b});
  h[a].push_back(e.size() - 1);
}

void tarjan(int x, int lastedge)
{
  dfn[x] = low[x] = ++tim;
  for (int j : h[x])
  {
    int y = e[j].second;
    if (!dfn[y])
    {
      tarjan(y, j);
      low[x] = min(low[x], low[y]);
      if (low[y] > dfn[x])
      {
        bri.push_back({x, y});
      }
    }
    else if (lastedge != (j ^ 1))
    {
      low[x] = min(low[x], dfn[y]);
    }
  }
}

signed main()
{
  IOS;
  int n, m;
  cin >> n >> m;
  int a, b;

  for (int i = 1; i <= m; i++)
  {
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!dfn[i])
      tarjan(i, 0);
  }

  sort(bri.begin(), bri.end());
  for (auto it : bri)
  {
    cout << it.x << " " << it.y << endl;
  }

  return 0;
}