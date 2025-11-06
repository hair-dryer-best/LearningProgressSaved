// https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int N = 100005;
int n, m, w[N];

struct SGT
{
#define lc u << 1
#define rc u << 1 | 1
  struct sgt
  {
    int l, r, sum, add;
  } tr[N*4];
  void pushup(int u)
  {
    tr[u].sum = tr[lc].sum + tr[rc].sum;
  }
  void pushdown(int u)
  {
    if (tr[u].add)
    {
      tr[lc].add += tr[u].add;
      tr[rc].add += tr[u].add;
      tr[lc].sum += tr[u].add * (tr[lc].r - tr[lc].l + 1);
      tr[rc].sum += tr[u].add * (tr[rc].r - tr[rc].l + 1);
      tr[u].add = 0;
    }
  }
  void build(int u, int l, int r)
  {
    tr[u] = {l, r, w[l], 0};
    if (l == r)
    {
      tr[u].sum = w[l];
      return;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(u);
  }
  void change(int u, int x, int y, int k)
  {
    if (tr[u].l > y || tr[u].r < x)
    {
      return;
    }
    if (x <= tr[u].l && tr[u].r <= y)
    {
      tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
      tr[u].add += k;
      return;
    }
    pushdown(u);//别忘了
    change(lc, x, y, k);
    change(rc, x, y, k);
    pushup(u);
  }
  int query(int u, int x, int y)
  {
    if (tr[u].l > y || tr[u].r < x)
    {
      return 0;
    }
    if (x <= tr[u].l && tr[u].r <= y)
    {
      return tr[u].sum;
    }
    pushdown(u);
    return query(lc, x, y) + query(rc, x, y);
  }
};
SGT tre;
signed main()
{
  IOS;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
  }

  tre.build(1, 1, n);
  while (m--)
  {
    int op;
    cin >> op;
    int x, y, k;
    if (op == 1)
    {
      cin >> x >> y >> k;
      tre.change(1, x, y, k);
    }
    else
    {
      cin >> x >> y;
      cout << tre.query(1, x, y) << endl;
    }
  }

  return 0;
}