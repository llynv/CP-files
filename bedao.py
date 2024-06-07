from sympy import symbols, integrate

x, b = symbols('x b')
expr = b / x**2
b_value = 1 / integrate(expr, (x, 1, 5))


print(b_value)