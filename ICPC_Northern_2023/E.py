M = 987654321

n = int(input())
a = (n - 2) * (n - 1) * (n * (n - 3) + 12) / 24;
print(int(a % M))