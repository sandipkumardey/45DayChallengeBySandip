# Power Function - No support for fractional powers
def pow(x, n):
    if n == 0:
        return 1
    elif n < 0:
        x, n = 1 / x, -n

    result = 1
    while n:
        if n % 2:
            result *= x
        x *= x
        n //= 2

    return result  # Does not handle fractional n
