
/*
  Code by: linvg
  Created: 06.10.2024 00:19:06
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int N = 1e7 + 7;

bitset<N> is_prime;
vector<array<int, 2>> ans;

void sieve() {
   is_prime.set();
   is_prime[0] = is_prime[1] = 0;
   for (int i = 2; i * i < N; ++i) {
      if (is_prime[i]) {
         for (int j = i * i; j < N; j += i) {
            is_prime[j] = 0;
         }
      }
   }
   ans.push_back({ 0, 0 });
   ans.push_back({ 5, 2 });
   for (int i = 7; i < N; i += 2) {
      if (is_prime[i] && is_prime[i - 2]) {
         ans.push_back({ i, ans.back()[1] + 1 });
      }
   }
}

void solve(int test_case)
{
   int n;
   cin >> n;
   int p = upper_bound(all(ans), array<int, 2>{ n, INF }) - ans.begin() - 1;
   cout << "Case #" << test_case << ": " << ans[p][1] << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   
   freopen("prime_subtractorization_input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   clock_t start = clock();
   sieve();
   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      solve(i);
   }
   cerr << "Time: " << (clock() - start) / (double)CLOCKS_PER_SEC << '\n';
   return 0;
}