t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    vst = [False] * n
    res = 0

    mul = 1
    for j in range(n):
        a[j] *= mul

        if x >= a[j]:
            res += 1
            x *= (j + 2)

        mul *= (j + 1)
    
    print(res)

        