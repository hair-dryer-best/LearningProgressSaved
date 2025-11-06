// 洛谷 https://www.luogu.com.cn/problem/P2812
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 10005;

int n, m;
vector<int> e[N];

int dfn[N], low[N], tim, stk[N], top;
int scc[N], cnt;
int din[N], dout[N];
void tarjan(int x)
{
  dfn[x] = low[x] = ++tim;
  stk[++top] = x;
  for (int y : e[x])
  {
    if (!dfn[y])
    {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    }
    else if (!scc[y])
    {
      low[x] = min(low[x], dfn[y]);
    }
  }
  if (dfn[x] == low[x])
  {
    ++cnt;
    while (1)
    {
      int y = stk[top--];
      scc[y] = cnt;
      if (y == x)
        break;
    }
  }
}

signed main()
{
  IOS;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int a;
    while (cin >> a)
    {
      if (a == 0)
      {
        break;
      }
      e[i].push_back(a);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (!dfn[i])
    {
      tarjan(i);
    }
  }
  for (int x = 1; x <= n; x++)
    for (int y : e[x])
      if (scc[x] != scc[y])
      {
        din[scc[y]]++;
        dout[scc[x]]++;
      }

  int ddin = 0, ddout = 0;
  for (int i = 1; i <= cnt; i++)
  {
    if (!din[i])
      ddin++;
    if (!dout[i])
      ddout++;
  }
  cout << ddin << "\n";
  if (cnt == 1)
  {
    cout << "0\n";
  }
  else
  {
    cout << max(ddin, ddout) << "\n";
  }

  return 0;
}