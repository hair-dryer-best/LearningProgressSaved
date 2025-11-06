// The 2025 ICPC Asia East Continent Online Contest (II)
// https://qoj.ac/contest/2524/problem/14316
// 题解:https://zhuanlan.zhihu.com/p/1950650448873764742
// 官方题解:https://zhuanlan.zhihu.com/p/1950637403929806516
/*关键点在于：对于任何队员的子集（例如只包含A、只包含B、包含A和B等），
这个子集中的队员能解决的题目总数除以子集的大小（队员人数）得到一个平均值。
这个平均值代表了子集中每个队员平均能解决的题目数量。由于题目分配必须平衡，
整个分配中最小值不会超过这个平均值对于任何子集。因此，我们需要考虑所有可能的子集，
计算每个子集的平均值，然后取这些平均值中的最小值。
这个最小值就是我们能达到的最大可能的最小值。*/

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 1000;
int S;
int F[8];

int bitt[8] = {0, 1, 1, 2, 1, 2, 2, 3}; // f各个集合的个数

void solve()
{
  cin >> S;
  for (int i = 1; i <= 7; i++)
    cin >> F[i];
  int ans = S;
  for (int i = 1; i <= 7; i++)
  {
    int cnt = bitt[i], tot = 0;
    for (int j = 1; j <= 7; j++)
    {
      if (j & i) // 有当前集合里的都加进去
        tot += F[j];
    }
    ans = min(ans, tot / cnt);
  }
  cout << ans << "\n";
}

signed main()
{
  IOS;
  int T;
  cin >> T;
  while (T--)
  {
    solve();
  }

  return 0;
}
/*
4
36
14 4 3 2 9 0 4
41
4 8 4 4 3 14 4
53
3 0 12 6 14 11 7
55
11 10 11 10 2 8 3
*/