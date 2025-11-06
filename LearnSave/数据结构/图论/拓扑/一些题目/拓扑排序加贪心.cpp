// https://tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=6082
// 为什么要建反图,然后逆序输出?
// 因为题目要把小的尽量放前面,正序贪心找小的会忽略掉之后更小的
// 反例:4 → 1   3 → 2 正序贪心会输出3241,实际答案为4132,就是因为忽略了后面更小的1导致的
// 所以转换思路,建反图找更大的,这样就可以每次把小的往后放,并且也能按照当前约束的顺序(→关系)输出结果
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
const int INF = 0x3f3f3f3f;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> e[n + 1];
  vector<int> ans;
  vector<int> in(n + 1, 0);
  int a, b;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    e[b].push_back(a);
    in[a]++;
  }

  priority_queue<int> que;
  for (int i = 1; i <= n; i++)
  {
    if (in[i] == 0)
    {
      que.push(i);
    }
  }

  while (que.size())
  {
    int u = que.top();
    que.pop();
    ans.push_back(u);
    for (auto it : e[u])
    {
      if (--in[it] == 0)
      {
        que.push(it);
      }
    }
  }

  reverse(ans.begin(), ans.end());
  copy(ans.begin(), ans.end() - 1, ostream_iterator<int>(cout, " ")); // for循环高级写法
  cout << ans.back() << "\n";
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