// https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=1697
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
using pii = pair<int, int>;
int d[10005];
signed main()
{
  IOS;
  int N, I, H, R;
  cin >> N >> I >> H >> R;
  d[1] = H;
  set<pii> seen; // 防止重复一对
  int x, y;
  for (int i = 0; i < R; i++)
  {
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    if (seen.find({x, y}) != seen.end())
    {
      continue;
    }
    seen.insert({x, y});
    d[x + 1] -= 1;
    d[y] += 1;
  }
  int pre_sum = 0;
  for (int i = 1; i <= N; i++)
  {
    pre_sum += d[i];
    cout << pre_sum << endl;
  }

  return 0;
}