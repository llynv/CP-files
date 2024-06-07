t = int(input())

for _ in range(t):
    n = int(input())
    
    isOk = True
    for i in range(2, 64):
        if n < 0 and i % 2 == 0: continue

        c = abs(n)
        rt = pow(c, 1.0/i).__round__()

        # print(rt, c, i)

        if c == rt ** i:
            print("Piccolo")
            isOk = False
            break

    if isOk:
        print("Majin Buu")