// 洛谷 https://www.luogu.com.cn/problem/P3379
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 5e5 + 10;
int son[N]; // 重儿子节点
int fa[N];  // 父亲节点
int dep[N]; // 深度
int top[N]; // 每条链的链头
int sz[N];  // 存u所在的重链顶点
vector<int> e[N];
// 函数注释见最下
void dfs1(int u, int f);
void dfs2(int u, int t);
int lca(int u, int v);
int n, m, s;
signed main()
{
  IOS;
  cin >> n >> m >> s;
  int u, v;

  for (int i = 1; i < n; i++)
  {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs1(s, s);
  dfs2(s, s);
  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    int ans = lca(u, v);
    cout << ans << "\n";
  }

  return 0;
}
void dfs1(int u, int f) // 找深度dep[],重儿子son[],节点数sz[],父节点fa[]
{
  fa[u] = f;
  dep[u] = dep[f] + 1;
  sz[u] = 1;
  for (auto v : e[u])
  {
    if (v == f)
    {
      continue;
    }
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v])
    {
      son[u] = v;
    }
  }
}
void dfs2(int u, int t)
{ // 找top数组（找每条链的链头）
  top[u] = t;
  for (int v : e[u])
  {
    if(v==fa[u]){
      continue;
    }
    if(v==son[u]){//是重儿子就继承，轻儿子就自己当头
      dfs2(son[u],t);
    }else{
      dfs2(v,v);
    }
  }
}
int lca(int u, int v)
{
  while (top[u] != top[v])
  {
    if (dep[top[u]] < dep[top[v]])
      swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}
