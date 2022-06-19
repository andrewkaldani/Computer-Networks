def Fib(n):
    if n < 0:
        return "not possible"
    elif n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return Fib(n-1) + Fib(n-2)

try:
    userInput = int(input("Enter a number greater than or equal to 0: "))
except ValueError:
    print("not a number or <= 0")

print(Fib(userInput))
