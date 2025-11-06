// https://codeforces.com/contest/2156/problem/C
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
const int N = 200005;

void solve()
{
  int k, n;
  cin >> n >> k;
  map<int, int> mp;
  int a;
  for (int i = 1; i <= n; i++)
  {
    cin >> a;
    mp[a]++;
  }
  vector<int> cnt(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cnt[i] = cnt[i - 1] + mp[i];
  }
  for (int d = n; d >= 1; d--)
  {
    int sum = mp[d] + mp[2 * d] + mp[3 * d];//sum为不用通过k来排除的数字
    if (4 * d <= n)
    {
      sum += cnt[n] - cnt[4 * d - 1];
    }
    if (sum >= n - k)
    {
      cout << d << endl;
      break;
    }
  }
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