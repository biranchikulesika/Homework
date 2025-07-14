def isPrime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def printPrimes(start, end):
    for num in range(start, end):
        if isPrime(num):
            print(num, end=" ")

start = int(input("Enter the start of the range: "))
end = int(input("Enter the end of the range: "))

print(f"The prime numbers between {start} and {end} are:")
printPrimes(start, end) 