n, k = map(int, input().split())

# dp[i][0] += dp[i-1][j] (j : 1 -> k-1)

# dp[i][j] += dp[i-1][j] (j : 0 -> k-1)

if (n == 1) :
   print(k)

else:

   dp = [[0] * 2 for _ in range(n+1)]

   dp[1][1] = 1

   for i in range(2, n+1):
      ssum = 0
      dp[i][0] += dp[i-1][1] * (k-1)
      dp[i][1] += dp[i-1][0] + dp[i-1][1] * (k-1)
         

   print(dp[n][0] + dp[n][1] * (k-1))