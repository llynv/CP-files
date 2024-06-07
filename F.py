t = int(input())

a = []
dic = {}

for _ in range(t):
   n = int(input())
   if n not in a:
      a.append(n)
   dic[n] = dic.get(n, 0) + 1

res = 0

for x in a:
   for i in a:
      if (x * i) in dic:
         res += dic[x * i] * dic[x] * dic[i]

print(res)
