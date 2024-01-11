import sys
sys.set

t = int(input())

flen = [0] * 6000

flen = 

for _ in range(t):
    l = 0 
    r = 5982
    ans = 0
    while l < r:
        m = (l + r) // 2
        print("? " + str(flen[m]-1))
        sys.stdout.flush()
        dif = int(input())

        if dif == flen[m]:
            ans = m
            break

        if dif != 0:
            l = m + 1
            ans = m + 1
        else:
            r = m

    if ans == 0:
        if dif == 1:
            print("! " + str(1))
        elif dif == 2:
            print("! " + str(2))
        elif dif == 6:
            print("! " + str(3))
        sys.stdout.flush()
    else:
        print("! " + str(ans))
        sys.stdout.flush()

    if input() != "YES":
        break
