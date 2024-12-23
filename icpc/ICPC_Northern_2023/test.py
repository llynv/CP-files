n = int(input())
M = 987654321
res = (n-2)*(n-1)*(n*(n-3) + 12) // 24
print(int(res % M))
