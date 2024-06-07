t = int(input())

for _ in range(t):
    n = int(input())

    res = int(pow(n, 0.5)) // 2
    if n % 2 != 0 and int(pow(n, 0.5)) ** 2 == n: 
        res += 1
    print(res)