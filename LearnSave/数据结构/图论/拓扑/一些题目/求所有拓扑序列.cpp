// TZOJ P6716 求所有拓扑序列
#include <bits/stdc++.h>
using namespace std;
const int N = 25;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
vector<int> tp(N + 1);
vector<int> e[N];
int din[N], n, m;
void toposort(int);
int main()
{
  IOS;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    din[b]++;
  }
  toposort(0);
  return 0;
}
void toposort(int step)
{
  bool found = false;
  for (int i = 1; i <= n; i++)
  {
    if (din[i] == 0)
    {
      found = true;
      tp[step] = i;
      din[i] = -1; // 标记为访问过
      for (auto ed : e[i])
      {
        --din[ed];
      }
      toposort(step + 1); // 递归调用下一次
      din[i] = 0;         // 回溯
      for (auto ed : e[i])
      {
        din[ed]++;
      }
    }
  }
  if (!found) // 序列生成完成
  {
    for (int i = 0; i < n; i++)
    {
      if (i)
        cout << " " << tp[i];
      else
        cout << tp[i];
    }
    cout << "\n";
  }
  return;
}
/*#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 25;
vector<int> tp;
vector<int> e[N];
int din[N], n, m;
void toposort();
int main()
{
  IOS;
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    din[b]++;
  }
  toposort();
  return 0;
}
void toposort()
{
  bool found = false;
  for (int i = 1; i <= n; i++)
  {
    if (din[i] == 0)
    {
      found = true;
      tp.push_back(i);
      din[i] = -1; // 标记为访问过
      for (auto ed : e[i])
      {
        --din[ed];
      }
      toposort(); // 递归调用下一次
      din[i] = 0; // 回溯
      for (auto ed : e[i])
      {
        din[ed]++;
      }
      tp.pop_back();
    }
  }
  if (!found) // 序列生成完成
  {
    for (int i = 0; i < tp.size(); i++)
    {
      if (i)
      {
        cout << " " << tp[i];
      }
      else
      {
        cout << tp[i];
      }
    }
    cout << "\n";
  }
  return;
}*/


