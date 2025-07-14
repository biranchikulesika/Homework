# Main program to print a pyramid pattern
num = int(input("Enter number: "))

for i in range(num):
    # Print leading spaces and numbers in a single loop
    print("  " * (num - i - 1), end="")  # Leading spaces
    print(" ".join(map(str, range(1, i + 2))), end=" ")  # Increasing numbers
    print(" ".join(map(str, range(i, 0, -1))))  # Decreasing numbers