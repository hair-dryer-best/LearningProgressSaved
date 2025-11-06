// https://www.luogu.com.cn/problem/P8865
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
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1005;
int n, m, c, f;
int mp[N][N];
int C_up[N][N];
int F_down[N][N];
int pre[N][N];
void init()
{
  memset(mp, 0, sizeof mp);
  memset(C_up, 0, sizeof C_up);
  memset(F_down, 0, sizeof F_down);
  memset(pre, 0, sizeof pre);
}

void solve()
{
  cin >> n >> m >> c >> f;
  ll C_mx = 0;
  ll F_mx = 0;
  init();
  string row;
  for (int i = 1; i <= n; i++)
  {
    cin >> row;
    for (int j = 1; j <= m; j++)
    {
      mp[i][j] = row[j - 1] - '0';
    }
  }
  for (int i = n; i >= 1; i--)
  {
    for (int j = m; j >= 1; j--)
    {
      if (mp[i][j] == 0)
        pre[i][j] = pre[i][j + 1] + 1;
      else
        pre[i][j] = 0;
    }
  }
  // C
  for (int j = 1; j <= m; j++)
  {
    for (int i = 1; i <= n; i++)
    {
      if (mp[i][j] == 0)
        C_up[i][j] = C_up[i - 1][j] + pre[i][j] - 1;
      else
        C_up[i][j] = 0;
    }
  }

  for (int i = 3; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      ll sum = 0;
      if (mp[i][j] == 0 && mp[i - 1][j] == 0)
      {
        sum = (C_up[i - 2][j]) * (pre[i][j] - 1);
        C_mx = (C_mx + sum) % MOD;
      }
    }
  }

  // F
  for (int j = 1; j <= m; j++)
  {
    for (int i = n; i >= 1; i--)
    {
      if (mp[i][j] == 0)
        F_down[i][j] = F_down[i + 1][j] + 1;
      else
        F_down[i][j] = 0;
    }
  }
  for (int i = 3; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      ll sum = 0;
      if (mp[i][j] == 0 && mp[i - 1][j] == 0)
      {
        sum = C_up[i - 2][j] * (pre[i][j] - 1) * (F_down[i][j] - 1);

        F_mx = (F_mx + sum) % MOD;
      }
    }
  }

  cout << (C_mx * c % MOD) << " " << (F_mx * f % MOD) << endl;
}

signed main()
{
  IOS;
  int T, id;
  cin >> T >> id;
  while (T--)
  {
    solve();
  }

  return 0;
}