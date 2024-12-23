def solve(m):
    k=0
    move=[]
    marble=1
    l = len(m)
    while marble < l:
        z = m.index(marble)
        if (z+1 != marble):
            k+=1
            move.append(f"{z+1} {len(m)+1}")
            for i in range(z, marble-1, -1):
                k+=1
                move.append(f"{i} {i+1}")
            k+=1
            move.append(f"{len(m)+1} {marble}")
        m.insert(marble-1, m.pop(z))
        marble+=1


    print(len(move))
    for i in move:
        print(i)
    
    return 0


if __name__ == "__main__":
    t=int(input())
    for _ in range(t):
        n=int(input())
        m=list(map(int,input().split()))
        solve(m)