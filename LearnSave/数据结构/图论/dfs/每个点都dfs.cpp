// https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=7995
// 全部dfs
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 2005;

bool dp[N][N];    
vector<int> e[N]; 
bool vis[N];      


void dfs(int start, int u)
{
  vis[u] = true;
  dp[start][u] = true;
  for (int v : e[u])
  {
    if (!vis[v])
    {
      dfs(start, v);
    }
  }
}

signed main()
{
  IOS;
  int n, m;
  cin >> n >> m;


  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
  }


  for (int i = 1; i <= n; i++)
  {
    memset(vis, 0, sizeof vis);
    dfs(i, i);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cnt+=dp[i][j];
    }
  }
  cout << cnt << endl;

  return 0;
}