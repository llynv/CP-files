n = int(input())
a = list(map(int, input().split()))

MOD = 10**9 + 7
res = 0

for i in range(-1, n):
   mul = 1
   for j in range(0, n):
      if i == j:
         continue
      mul *= a[j]
   res = max(res, mul)

print(res % MOD)  