# Write a program to check whether a number is Armstrong or not.

def isArmstrong(num):
    count = len(str(num))

    temp = num
    sum = 0

    while temp != 0:
        digit = temp % 10
        sum += digit**count
        temp //= 10

    return num == sum

print("Check Armstrong.")
number = int(input("Enter the number: "))

if isArmstrong(number):
    print(f"{number} is Armstrong.")
else:
    print(f"{number} is not Armstrong.")