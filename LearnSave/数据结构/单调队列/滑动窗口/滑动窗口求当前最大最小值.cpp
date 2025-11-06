// https://www.luogu.com.cn/problem/P1886
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
const int N = 1000;

signed main()
{
  IOS;
  int n, k;
  cin >> n >> k;
  deque<int> small;
  deque<int> big;
  vector<int> arr;
  vector<int> ans_s;
  vector<int> ans_b;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    arr.push_back(a);
    while (!small.empty() && arr[small.back()] >= a)
    {
      small.pop_back();
    }
    while (!big.empty() && arr[big.back()] <= a)
    {
      big.pop_back();
    }

    small.push_back(i);
    big.push_back(i);

    if (i - k + 1 > small.front())
    {
      small.pop_front();
    }
    if (i - k + 1 > big.front())
    {
      big.pop_front();
    }
    if (i >= k - 1)
    {
      ans_s.push_back(arr[small.front()]);
      ans_b.push_back(arr[big.front()]);
    }
  }
  for (auto it : ans_s)
  {
    cout << it << " ";
  }
  cout << endl;
  for (int it : ans_b)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}