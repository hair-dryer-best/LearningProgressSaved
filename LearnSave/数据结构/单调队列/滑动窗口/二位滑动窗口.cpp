// https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=1515
//可以转化为经典的前缀和加滑动窗口问题
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;

signed main()
{
  IOS;
  int r, c, k;
  while (1)
  {
    cin >> r >> c >> k;
    if (r == 0 && c == 0 && k == 0)
    {
      break;
    }
    int mi = INF;
    vector<vector<char>> mp(r + 2, vector<char>(c + 2));
    vector<vector<int>> pre(r + 2, vector<int>(c + 2, 0));

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        cin >> mp[i][j];
        int val = (mp[i][j] == '.') ? 1 : 0;
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + val;
      }
    }

    auto Sum = [&](int x1, int y1, int x2, int y2) -> int
    {
      return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };

    for (int i = 1; i <= r; i++)
    {
      for (int j = i; j <= r; j++)
      {
        int left = 1;
        for (int right = 1; right <= c; right++)
        {
          // 计算当前窗口 [i, left] 到 [j, right] 的可用座位数
          int currentSum = Sum(i, left, j, right);

          // 收缩左边界
          while (left <= right && currentSum >= k)
          {
            int area = (j - i + 1) * (right - left + 1);
            mi = min(mi, area);

            left++;
            if (left <= right)
            {
              currentSum = Sum(i, left, j, right);
            }
          }
        }
      }
    }
    cout << mi << endl;
  }

  return 0;
}