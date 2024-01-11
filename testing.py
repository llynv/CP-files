import math

t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = [0]*(n+1)
    res = 0
    for i in range(1, n):
        h = math.ceil(math.log2(a[i-1]/a[i])) + ans[i-1]
        ans[i] = max(h, 0)
    
    print(sum(ans))