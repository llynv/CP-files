n, p = [int(x) for x in input().split()]
res = 1
for i in range(p):
    res *= n
print(res)