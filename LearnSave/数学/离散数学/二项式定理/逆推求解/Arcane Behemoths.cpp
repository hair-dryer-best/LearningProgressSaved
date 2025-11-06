// The 2025 ICPC Asia East Continent Online Contest (II)
// 题目链接https://qoj.ac/contest/2524/problem/14317
// 题解 :https://zhuanlan.zhihu.com/p/1950650448873764742
#include <bits/stdc++.h>
const int N = 22e4, p = 998244353;
using namespace std;
int n, a[N], ans;
int pw(int a, int b)
{
  int rs = 1;
  for (; b; b /= 2, a = 1ll * a * a % p)
    if (b & 1)
      rs = 1ll * rs * a % p;
  return rs;
}
int f(int k)
{
  return (p + 1ll) / 2 * (pw(3, k - 1) + 1) % p * pw(2, n - k) % p;
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n, ans = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
      ans = (ans + 1ll * a[i] * f(i)) % p;
    cout << ans << '\n';
  }
  return 0;
}