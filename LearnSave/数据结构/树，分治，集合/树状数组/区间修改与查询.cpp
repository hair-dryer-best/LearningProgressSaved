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
/*
a [ 1 ] + a [ 2 ] + a [ 3 ] + … + a [ r ]
= d [ 1 ] + ( d [ 1 ] + d [ 2 ] ) + ( d [ 1 ] + d [ 2 ] + d [ 3 ]) + … + ( d [ 1 ] + d [ 2 ] + … + d [ r ] )
= d [ 1 ] * r + d [ 2 ] * ( r - 1 ) + d [ 3 ] * ( r - 2 ) +…+ d [ r ]
= ( d [ 1 ] + d [ 2 ] + … + d [ r ] ) * r - ( d [ 1 ] * 0 + d [ 2 ] * 1 + … + d [ r ] * ( r - 1 ) )
我们化到这个样子就行了。

这时候，我们开 两棵树状数组 分别为 s1 存 d [ i ] 和 s2 存d [ i ] * ( i - 1 )
就能写出查询 x 到 y 的 区间和
sum = ( query ( s1 , y ) * y - query ( s2 , y ) ) - ( query ( s1 , x - 1 ) * ( x - 1 ) - query ( s2 , x - 1) )
前面 被减数是表示 1 ~ y 的和
后面 减数是 1 ~ x - 1 的和 ，总的求出 sum 就是 区间 x ~ y 的和；
*/