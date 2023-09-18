
def gcd (a, b):
	return a if b == 0 else gcd(b, a % b)

def Lcm (a, b):
    return a * b / gcd(a, b)

l = int(input())
r = int(input())
a = int(input())
k = int(input())

rr = int(r * a)
ll = int((l - 1) * a)
target = Lcm(a, k)

print(int(rr / target) - int(ll / target))