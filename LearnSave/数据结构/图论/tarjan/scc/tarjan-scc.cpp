// 洛谷: https://www.luogu.com.cn/problem/P2863
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const ll INF = 1e9;
const int N = 20005;
vector<int> e[N];
int dfn[N], low[N], tim, stk[N], ins[N], top, scc[N], siz[N], cnt;
int ans;

void tarjan(int x)
{
  dfn[x]=low[x]=++tim; //时间戳 追溯值
  stk[++top] = x, ins[x] = 1;
  for (int y : e[x])
  {
    if (!dfn[y])
    { // 若y尚未访问
      tarjan(y);
      low[x] = min(low[x], low[y]); // 因y是儿子
    }
    else if (ins[y])                // 若y已访问且在栈中
      low[x] = min(low[x], dfn[y]); // 因y是祖先或左子树点
  }

  if (dfn[x] == low[x])
  { // 若x是SCC的根
    ++cnt;
    while (1)
    {
      int y = stk[top--];
      ins[y] = 0;
      scc[y] = cnt; // SCC的编号
      ++siz[cnt];   // SCC的大小
      if (y == x)
        break;
    }
  }
}

signed main()
{
  IOS;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) // 可能不连通
    if (!dfn[i])
      tarjan(i);
  for (int i = 1; i <= cnt; i++)
    if (siz[i] > 1)
      ans++;
  cout << ans;

  return 0;
}