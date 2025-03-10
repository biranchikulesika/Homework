# Write a program to find the factorial of a number

def factorial(num):
    fact = 1
    for i in range(1, num + 1):
        fact *= i
    return fact

number = int(input("Enter the number to find the factorial: "))
fact = factorial(number)

print(f"The factorial of {number} is: {fact}")
