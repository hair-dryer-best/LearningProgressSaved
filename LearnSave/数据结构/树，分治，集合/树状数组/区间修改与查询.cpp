// https://www.luogu.com.cn/problem/P3372
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
// #define int long long
using ll = long long;
const int N = 1e5 + 5;
int n, m;
struct BIT
{
#define lowbit(x) x & -x
  ll sum[N];
  void change(int x, ll k)
  {
    while (x <= n)
    {
      sum[x] += k;
      x += lowbit(x);
    }
  }
  ll query(int x)
  {
    ll res = 0;
    while (x)
    {
      res += sum[x];
      x -= lowbit(x);
    }
    return res;
  }
};
BIT a, b;

signed main()
{
  IOS;
  cin >> n >> m;
  ll k;
  for (int i = 1; i <= n; i++)
  {
    cin >> k;
    a.change(i, k);
    a.change(i + 1, -k);
    b.change(i, k * (i - 1));
    b.change(i + 1, -k * i);
  }
  int op, x, y;
  while (m--)
  {
    cin >> op >> x >> y;
    if (op == 1)
    {
      cin >> k;
      a.change(x, k);
      a.change(y + 1, -k);
      b.change(x, k * (x - 1));
      b.change(y + 1, -k * y);
    }
    else
    {
      cout << (a.query(y) * y - b.query(y)) - (a.query(x - 1) * (x - 1) - b.query(x - 1)) << endl;
    }
  }

  return 0;
}
