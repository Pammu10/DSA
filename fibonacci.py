def fib(n):
    memo = [0]*(n+1)
    memo[0] = 0
    memo[1] = 1
    if memo[n]:
        return memo[n]
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        result = fib(n-1) + fib(n-2)
        memo[result] = result
        return result
    
def fib2(n):
    arr = [0]*(n+1)
    arr[1] = 1
    for i in range(1, n):
        arr[i+1] = arr[i] + arr[i-1]
    return arr[i+1]

print(fib2(100))
print(fib(100))


