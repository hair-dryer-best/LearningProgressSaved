// https://www.luogu.com.cn/problem/P3384
// 稍后修改的更加可视化的写法！
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const ll INF = 1e9;
const int N = 100010;
#define lc u << 1
#define rc u << 1 | 1

int n, m, root, P, w[N], a, b, c, t;
vector<int> e[N];

int fa[N], dep[N], siz[N], son[N];
int top[N], id[N], nw[N], cnt;
struct tree
{
  int l, r;
  int sum, add;
} tr[N * 4];
// 重链剖分部分
void dfs1(int u, int f)
{
  fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
  for (int v : e[u])
  {
    if (v == f)
      continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[son[u]] < siz[v])
    {
      son[u] = v;
    }
  }
}

void dfs2(int u, int tp)
{
  top[u] = tp, id[u] = ++cnt, nw[cnt] = w[u];
  if (son[u])
  {
    dfs2(son[u], tp);
  }
  for (int v : e[u])
  {
    if (v == fa[u] || v == son[u])
      continue;
    dfs2(v, v);
  }
}

// 线段树的部分

void pushup(int u)
{
  tr[u].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int u)
{
  if (tr[u].add)
  {
    tr[lc].sum += tr[u].add * (tr[lc].r - tr[lc].l + 1);
    tr[rc].sum += tr[u].add * (tr[rc].r - tr[rc].l + 1);
    tr[lc].add += tr[u].add;
    tr[rc].add += tr[u].add;
    tr[u].add = 0;
  }
}

void build(int u, int l, int r)
{
  tr[u] = {l, r, nw[l], 0};
  if (l == r)
    return;
  int mid = l + r >> 1;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  pushup(u);
}

void change(int u, int x, int y, int k)
{
  if (x > tr[u].r || y < tr[u].l)
    return;
  if (x <= tr[u].l && tr[u].r <= y)
  {
    tr[u].sum += k * (tr[u].r - tr[u].l + 1);
    tr[u].add += k;
    return;
  }
  pushdown(u);
  change(lc, x, y, k);
  change(rc, x, y, k);
  pushup(u);
}

int query(int u, int x, int y)
{
  if (x > tr[u].r || y<tr[u].l)
    return 0;
  if (x <= tr[u].l && tr[u].r<=y)
    return tr[u].sum;
  pushdown(u);
  return query(lc, x, y) + query(rc, x, y);
}

void change_path(int u, int v, int k)
{
  while (top[u] != top[v])
  {
    if (dep[top[u]] < dep[top[v]])
    {
      swap(u, v);
    }
    change(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v])
    swap(u, v);
  change(1, id[v], id[u], k);
}

int query_path(int u, int v)
{
  int res = 0;
  while (top[u] != top[v])
  {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    res += query(1, id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v])
    swap(u, v);
  res += query(1, id[v], id[u]);
  return res;
}

void change_tree(int u, int k)
{
  change(1, id[u], id[u] + siz[u] - 1, k);
}

int query_tree(int u)
{
  return query(1, id[u], id[u] + siz[u] - 1);
}

signed main()
{
  IOS;
  cin >> n >> m >> root >> P;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs1(root, 0);
  dfs2(root, root);
  build(1, 1, n);
  while (m--)
  {
    cin >> t >> a;
    if (t == 1)
    {
      cin >> b >> c;
      change_path(a, b, c);
    }
    else if (t == 2)
    {
      cin >> b;
      cout << query_path(a, b) % P << "\n";
    }
    else if (t == 3)
    {
      cin >> c;
      change_tree(a, c);
    }
    else
    {
      cout << query_tree(a) % P << "\n";
    }
  }

  return 0;
}