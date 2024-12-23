MOD = 10**9 + 7

def solve():
   n, k = map(int, input().split())
   if k == 1:
      print(n)
      return
   fi, se = 1, 1
   step = 0
   i = 3
   n %= MOD;
   while True:
      fibo = fi + se
      fibo %= k
      if fibo == 0:
         step = i
         break
      fi = se
      se = fibo
      i += 1
   print((step * n) % MOD)

if __name__ == '__main__':
   t = int(input())
   for _ in range(t):
      solve()