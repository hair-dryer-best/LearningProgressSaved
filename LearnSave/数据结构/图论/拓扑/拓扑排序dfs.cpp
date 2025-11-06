// 洛谷链接:https://www.luogu.com.cn/problem/B3644
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, a, b;
vector<int> e[N], tp;
int c[N];//染色数组
bool f = 1;

void dfs(int x)
{
  if (f == 0)
  {
    return;
  }
  c[x] = -1;
  for (int y : e[x])
  {
    if (c[y] == 1)
    {
      f = 0;
      return;
    }
    else if (c[y] == 0)
    {
      dfs(y);
      if (f == 0)
        return;
    }
  }
  c[x] = 2;
  tp.push_back(x);
}

bool topo()
{
  memset(c, 0, sizeof c);
  for (int x = 1; x <= n; x++)
  {
    if (c[x] == 0)
    {
      dfs(x);
      if (f == 0)
        return 0;
    }
  }
  reverse(tp.begin(), tp.end());
  return 1;
}

signed main()
{
  IOS;
  cin >> n;
  for (int i = 1, j; i <= n; i++)
  {
    while (cin >> j, j)
    {
      e[i].push_back(j);
    }
  }
  topo();
  for (int i = 0; i < n; i++)
  {
    cout << tp[i] << " ";
  }
  cout << "\n";

  return 0;
}