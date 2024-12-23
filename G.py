def solve():
   n = int(input())
   mp = {}

   def ask(l, r):
      if (l, r) in mp:
         return mp[(l, r)]
      print(f"xor {l} {r}")
      res = int(input())
      mp[(l, r)] = res
      return res

   t = ask(1, n)
   if t != 0:
      l, r = 1, n
      first = second = third = 0
      p1 = p2 = 0
      while l <= r:
         m = (l + r) // 2
         x = ask(1, m)
         if x != 0:
            r = m - 1
            first = x
            p1 = m
         else:
            l = m + 1
      l, r = p1 + 1, n
      while l <= r:
         m = (l + r) // 2
         x = ask(1, m)
         if x != 0 and x != first:
            r = m - 1
            second = x
            second ^= first
         else:
            l = m + 1
      third = t ^ first ^ second
      print(f"ans {first} {second} {third}")
      return

   start = 1
   x = ask(1, start)
   while x == 0 and start < n:
      start <<= 1
      x = ask(1, start)
   l, r = 1, start
   first = 0
   while l <= r:
      m = (l + r) // 2
      y = ask(1, m)
      if y != 0:
         first = y
         r = m - 1
      else:
         l = m + 1
   second = 0
   if first != x:
      second = x
      third = first ^ second
      print(f"ans {first} {second} {third}")
   else:
      l, r = start + 1, n
      third = 0
      while l <= r:
         m = (l + r) // 2
         y = ask(1, m)
         if y == 0:
            r = m - 1
         else:
            second = x ^ y
            third = first ^ second
            l = m + 1
      print(f"ans {first} {second} {third}")

if __name__ == "__main__":
   t = int(input())
   for _ in range(t):
      solve()