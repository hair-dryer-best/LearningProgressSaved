// TZOJ https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=9471
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define int long long
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;

signed main()
{
  IOS;
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &ai : a)
    cin >> ai;
  sort(all(a));//核心出装
  deque<int> q;
  int mx = 0;
  vector<int> dp(n); // 以i为结尾的最长长度
  int pre_mx = 0;    // 在这之前的最大长度
  for (int i = 0; i < n; ++i)
  {
    q.push_back(a[i]);
    while (q.back() - q.front() > k)
    {
      const int j = i - q.size() + 1;
      pre_mx = max(pre_mx, dp[j]); // 更新之前最大值
      q.pop_front();
    }
    dp[i] = q.size();
    mx = max(mx, dp[i] + pre_mx);
  }
  cout << mx << endl;
  return 0;
}