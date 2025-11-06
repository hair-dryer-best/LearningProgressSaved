//TZOJ P8217 https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=8217
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using ll = long long;
using pii = pair<int, int>;
using pli = pair<long long, int>;
const ll INF = 1e9;
const int N = 550;
int n, k;

struct edge
{
  int to;
  int val;
};
struct Node
{
  int x, y;
  bool operator<(Node &p)
  {
    if (x != p.x)
    {
      return x < p.x;
    }
    else
    {
      return y < p.y;
    }
  }
  bool operator>=(Node &p)
  {
    if (x >= p.x && y >= p.y)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

vector<Node> Point;
vector<edge> e[N];
int dp[N][N]; // dp[i][j]：表示以排序后第i个点为序列终点，且已经使用j个添加点时，能获得的最长序列长度

int dist(Node a, Node b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve()
{
  cin >> n >> k;
  Point.push_back({0, 0});
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    Point.push_back({x, y});
  }

  sort(Point.begin() + 1, Point.end());

  for (int i = 1; i <= n - 1; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (Point[j] >= Point[i])
      {
        int d=dist(Point[i], Point[j]);
        int need=d-1;
        if(need<=k){//添加实际距离，不加就错了
          e[i].push_back({j,need});
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      dp[i][j] = 1 + j;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (auto &it : e[i])
    {
      int v = it.to, need = it.val;
      for (int j = need; j <= k; j++)
      {
        dp[v][j] = max(dp[v][j], dp[i][j - need] + 1 + need);//i到v的最长
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++)
      ans = max(ans, dp[i][j] + (k - j));
  cout << ans << "\n";
}
signed main()
{
  IOS;
  solve();
  return 0;
}