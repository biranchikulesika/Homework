# Main program to print a pyramid pattern
num = int(input("Enter number: "))
i = 0

while i < num:
    # Print leading spaces
    for j in range(num - i - 1):
        print("  ", end="")

    # Print increasing numbers
    for k in range(1, i + 2):
        print(k, end=" ")

    # Print decreasing numbers
    for l in range(i, 0, -1):
        print(l, end=" ")

    # Move to the next line
    print()
    i += 1