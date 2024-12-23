#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int modindrome(int x) {
   int count = 0;
   while (x > 0) {
      if (x % 10 == x % 10) {
         count++;
      }
      x /= 10;
   }
   return count;
}

int solve(int N, int M) {
   vector<int> dp(M + 1, 0);
   dp[1] = 1;

   for (int i = 2; i <= M; i++) {
      for (int j = 1; j <= min(i, N); j++) {
         dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
   }

   int sum = 0;
   for (int i = 1; i <= M; i++) {
      sum = (sum + dp[i]) % MOD;
   }
   return sum;
}

int main() {
   int T;
   cin >> T;
   int totalN = 0, totalM = 0;
   while (T--) {
      int N, M;
      cin >> N >> M;
      totalN += N;
      totalM += M;
      if (totalN > 2 * 1e5 || totalM > 2 * 1e5) {
         cout << "Constraints exceeded" << endl;
         return 1;
      }
      cout << solve(N, M) << endl;
   }
   return 0;
}