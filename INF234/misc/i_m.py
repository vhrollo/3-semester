#karatsuba's algorithm
#changed so that it can take on any equal lenght int 
from math import ceil

def karatsuba(x: int, y: int):
    if x < 10 and y < 10:
        return x*y

    n = max(len(str(x)), len(str(y)))
    m = ceil(n/2)
    #given 23 times 23456
    #these make them seem like input looks like this 000023 023456
    x_H = x // (10**m)
    x_L = x % (10**m)

    y_H = y // (10**m)
    y_L = y % (10**m)

    a = karatsuba(x_H, y_H)
    b = karatsuba(x_L, y_L)
    c = karatsuba(x_H + x_L, y_H + y_L) - a - b

    return (a*(10**(2*m))) + (c*(10**(m))) + b

print(karatsuba(12345,1234))
