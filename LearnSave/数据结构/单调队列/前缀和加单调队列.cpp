/*
https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=6690
前缀和加单调队列
*/

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;

signed main()
{
  IOS;
  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 5, 0);
  int mx = LLONG_MIN;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    arr[i] += arr[i - 1];
    // cout<<arr[i]<<" ";
  }
  // cout<<endl;
  deque<int> que;
  que.push_back(0); // 关键的加一个前缀0,考虑从序列开头开始的子序列
  for (int i = 1; i <= n; i++)
  {
    // i为当前在i位置往前能找到的最小值
    while (que.size() && que.front() < i - m)
    {
      que.pop_front();
    }
    if (!que.empty())
    {
      mx = max(mx, arr[i] - arr[que.front()]);
    }
    while (que.size() && arr[que.back()] >= arr[i])
    {
      que.pop_back();
    }

    que.push_back(i);
  }

  cout << mx << endl;

  return 0;
}