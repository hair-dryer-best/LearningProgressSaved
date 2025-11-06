// https://www.luogu.com.cn/problem/P3865
#include <bits/stdc++.h>
using namespace std;
class ST
{
private:
  vector<vector<int>> st;
  int n;

public:
  ST(const vector<int> &arr)
  {
    n = arr.size();
    int k = log2(n) + 1;
    st.resize(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
      st[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
      for (int i = 0; i + (1 << j) <= n; i++)
      {
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r)
  {
    l--;
    r--;
    int j = log2(r - l + 1);
    return max(st[l][j], st[r - (1 << j) + 1][j]);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  ST st(arr);

  while (m--)
  {
    int x, y;
    cin >> x >> y;
    cout << st.query(x, y) << '\n';
  }

  return 0;
}