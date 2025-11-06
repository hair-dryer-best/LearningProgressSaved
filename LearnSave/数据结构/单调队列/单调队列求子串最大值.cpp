// TZOJ https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=9474
/*
问题转化
对于每个右端点r，我们想找到左端点l，使得：

r - m ≤ l ≤ r

prefix[r+1] - prefix[l] 最大

这等价于：对于固定的r，找到l ∈ [r-m, r]，使得prefix[l]最小。

*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using ll = long long;
signed main()
{
  IOS;
  int n, m;
  cin >> n >> m;
  vector<ll> pre(n + 5);
  for (int i = 1; i <= n; i++)
  {
    cin >> pre[i];
    pre[i] += pre[i - 1];
  }
  deque<int> que;
  ll mx = LLONG_MIN;
  que.push_back(0);
  for (int i = 1; i <= n; i++)
  {
    while (!que.empty() && que.front() < i - m)
    {
      que.pop_front();
    }
    if (!que.empty())
    {
      mx = max(pre[i] - pre[que.front()], mx);
    }
    while (!que.empty() && pre[que.back()] >= pre[i])
    {
      que.pop_back();
    }
    que.push_back(i);
  }
  cout << mx << endl;

  return 0;
}