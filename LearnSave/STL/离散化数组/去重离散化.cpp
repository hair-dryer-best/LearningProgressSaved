// 重复算相同排序的离散化
// 原来相等的值离散化后仍然相等
// https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=7713
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
const int N = 100005;
vector<int> arr(N);
vector<int> brr(N);
map<int, int> mp;

signed main()
{
  IOS;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    brr[i] = arr[i];
  }
  sort(arr.begin(), arr.begin() + n);
  int len = unique(arr.begin(), arr.begin() + n) - arr.begin();
  for (int i = 0; i < n; i++)
  {
    int x = lower_bound(arr.begin(), arr.begin() + len, brr[i]) - arr.begin() + 1;
    mp[brr[i]] = x;
  }
  int op;
  for (int i = 0; i < q; i++)
  {
    cin >> op;
    if (mp.find(op) == mp.end())
    {
      cout << "None" << endl;
    }
    else
    {
      cout << mp[op] << endl;
    }
  }

  return 0;
}