// 洛谷链接：https://www.luogu.com.cn/problem/B3644
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> e[N], tp;
int in[N]; // 存入度
int n;
bool toposort()
{
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (!in[i])
    { // 如果入度为0
      q.push(i);
    }
  }
  while (q.size())
  {
    int u = q.front();
    q.pop();
    tp.push_back(u); // 记录拓扑序
    for (auto v : e[u])
    {
      if (--in[v] == 0)
      {
        q.push(v);
      }
    }
  }
  return tp.size() == n;
}

signed main()
{
  IOS;
  cin >> n;
  for (int i = 1, j; i <= n; i++)
  {
    while (cin >> j, j)
    {
      e[i].push_back(j);
      in[j]++;
    }
  }
  toposort();
  for (int i = 0; i < n; i++)
  {
    cout << tp[i] << " ";
  }
  cout << "\n";

  return 0;
}