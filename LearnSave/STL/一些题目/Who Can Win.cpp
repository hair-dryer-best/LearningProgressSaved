// The 2025 ICPC Asia East Continent Online Contest (I)
// 原题链接 https://qoj.ac/contest/2513/problem/14301

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, long long>;
const int INF = 0x3f3f3f3f;
const int N = 100010;

struct unNode
{
  int ti;
  char pro;
  bool operator<(unNode b)
  {
    return ti < b.ti;
  }
};

struct Node
{
  int ti;
  char pro;
  string sta;
  bool operator<(Node b)
  {
    if (ti != b.ti)
      return ti < b.ti;
  }
};

void solve()
{
  int n;
  cin >> n;
  // 分为未知和已知
  map<string, vector<unNode>> unknow;
  map<string, vector<Node>> know;
  // set自动按string字典序排序
  set<string> team;

  map<string, pii> fina; // 把unknow加上后的解题次数和时间(时间取相反数因为越大越小)

  string name, sta;
  char pro;
  int ti;
  for (int i = 1; i <= n; i++)
  {
    cin >> name >> pro >> ti >> sta;
    team.insert(name);
    if (sta == "Unknown")
    {
      unknow[name].pb({ti, pro});
    }
    else
    {
      know[name].pb({ti, pro, sta});
    }
  }
  bool sv[30]; // 解决的题目
  int cnt[30]; // 错了的次数
  pii mx(-1, -1);
  // 对于每一队进行遍历
  for (auto te : team)
  {
    auto v = know[te];
    sort(all(v)); // 按照时间排序
    for (int i = 0; i < 27; i++)
    {
      sv[i] = false;
      cnt[i] = 0;
    }
    int pt = 0, ps = 0;
    // 用掉的时间 和 pass的题目
    for (auto [tim, prob, sta] : v)
    {
      int i = prob - 'A';
      if (sta == "Accepted")
      {
        if (!sv[i])
        {
          sv[i] = true;
          ps++;
          pt += 20 * cnt[i] + tim;
        }
      }
      else
      {
        if (!sv[i])
        {
          cnt[i]++;
        }
      }
    }
    // 求出当前最大值
    mx = max(mx, {ps, -pt}); // pt越小越大所以用负号反转
    // 加上当前队伍未知的
    auto v2 = unknow[te];
    sort(all(v2));

    for (auto [p1, prob] : v2)
    {
      int i = prob - 'A';
      if (!sv[i])
      {
        sv[i] = true;
        ps++;
        pt += 20 * cnt[i] + p1;
      }
    }
    fina[te] = {ps, -pt};
  }
  for (auto te : team)
  {
    if (fina[te] >= mx)
    {
      cout << te << " ";
    }
  }
  cout << "\n";
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

// 借鉴代码
/*#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define per(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define pb push_back
#define eb emake_pairlace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int, int> PII;

const int N = 1001000;
int n, m;
int sv[30], cnt[30];
void solve()
{
  cin >> n;
  map<string, vector<pair<int, pair<string, string>>>> nk;
  map<string, vector<pair<int, string>>> unk;
  set<string> tem;
  map<string, PII> t2;
  for (int i = 0; i < n; i++)
  {
    string name, prob, sta;
    int t;
    cin >> name >> prob >> t >> sta;
    tem.insert(name);
    if (sta == "Unknown")
      unk[name].pb(make_pair(t, prob));
    else
    {
      nk[name].pb(make_pair(t, make_pair(prob, sta)));
    }
  }
  PII mx(-1, -1);
  for (auto t : tem)
  {
    auto v = nk[t];
    sort(all(v));
    rep(i, 0, 26) sv[i] = 0, cnt[i] = 0;
    int pt = 0, ps = 0;
    for (auto [p1, p2] : v)
    {
      auto [prob, sta] = p2;
      int i = prob[0] - 'A';
      if (sta == "Accepted")
      {
        if (!sv[i])
        {
          sv[i] = 1;
          ps++;
          pt += 20 * cnt[i] + p1;
        }
      }
      else
      {
        if (!sv[i])
          cnt[i]++;
      }
    }
    mx = max(mx, make_pair(ps, -pt));
    // cout<<t<<" "<<pt<<" "<<ps<<"\n";
    auto v2 = unk[t];
    sort(all(v2));
    for (auto [p1, prob] : v2)
    {
      int i = prob[0] - 'A';
      if (!sv[i])
      {
        sv[i] = 1;
        ps++;
        pt += 20 * cnt[i] + p1;
      }
    }
    t2[t] = make_pair(ps, -pt);
  }
  for (auto t : tem)
    if (t2[t] >= mx)
    {
      cout << t << " ";
    }
  cout << "\n";
}
int _;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (cin >> _; _; _--)
  {
    solve();
  }
}*/