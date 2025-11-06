// https://www.luogu.com.cn/problem/P3375
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int n, m;
string s1, s2;

void kmp(vector<int> &nxt)
{
  nxt[1] = 0;
  for (int i = 2, j = 0; i <= m; i++)
  {
    while (j && s2[i] != s2[j + 1])
      j = nxt[j];
    if (s2[i] == s2[j + 1])
      j++;
    nxt[i] = j;
  }
  for (int i = 1, j = 0; i <= n; i++)
  {
    while (j && s1[i] != s2[j + 1])
      j = nxt[j];
    if (s1[i] == s2[j + 1])
      j++;
    if (j == m)
      cout << (i - m + 1) << endl;
  }
}

signed main()
{
  IOS;
  cin >> s1 >> s2;
  n = s1.length();
  m = s2.length();
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  vector<int> nxt(n + 1, 0);
  kmp(nxt);
  for (int i = 1; i <= m; i++)
    cout << nxt[i] << " ";

  return 0;
}