// TZOJ https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=8550
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
using u32 = unsigned int;
using u64 = unsigned long long;

vector<int> e[N];
vector<pii> query[N];
int ans[N];
bool vis[N];
int fa[N];
int find(int u)
{
  if (u == fa[u])
  {
    return u;
  }
  return fa[u] = find(fa[u]);
}

void tarjan(int u)
{
  vis[u] = true;
  for (auto v : e[u])
  {
    if (!vis[v])
    {
      tarjan(v);
      fa[v] = u;
    }
  }
  for (auto q : query[u])
  {
    int v = q.first, i = q.second;
    if (vis[v])
    {
      ans[i] = find(v);
    }
  }
}

void solve()
{
  int n, m, s;
  cin >> n >> m >> s;
  memset(vis, false, sizeof vis);
  for (int i = 1; i <= n; i++)
  {
    fa[i] = i;
  }
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    query[u].push_back({v, i});
    query[v].push_back({u, i});
  }
  tarjan(s);
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << "\n";
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