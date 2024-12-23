with open ('input.txt') as f:
    t = 10**4
    f.writelines(t)
    for i in range(1, t):
        f.writelines(1, 10**9)

    f.close()