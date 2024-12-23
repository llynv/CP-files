/*
    Code by: KoKoDuDu
    Created: 13.10.2024 10:29:30
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int MX = 11;

void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   set<char>st;
   for (int i = 0; i < s.size();++i) {
      st.insert(s[i]);
   }
   string save = "";
   for (auto i : st) {
      save += i;
   }
   map<char, int>pos;
   for (int i = 0; i < save.size(); ++i) {
      pos[save[i]] = i;
   }
   int ans = 0;
   int sz = (int)save.size();
   map<vector<int>, int> cnt;
   vector<int> t;
   for (int j = 0; j < save.size(); ++j) {
      t.push_back(0);
   }
   cnt[t]++;
   vector<vector<int>>state(n + 1, vector<int>(sz + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < save.size(); ++j) {
         if (s[i - 1] == save[j]) {
            state[i][j]++;
            state[i][j] %= MOD;
         }
         state[i][j] += state[i - 1][j];
         state[i][j] %= MOD;
      }
      vector<int> tmp;
      for (int j = 0; j < save.size(); ++j) {
         // cout << state[i][j] * sz - i << " ";
         tmp.push_back((state[i][j] * sz - i) % MOD);
      }
      ans += cnt[tmp];
      ans %= MOD;
      cnt[tmp]++;
      cnt[tmp] %= MOD;
      // cout << "\n";
   }
   cout << ans % MOD;

}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}