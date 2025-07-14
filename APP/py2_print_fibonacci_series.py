# Write a python program to print the Fibonacci Series upto n terms.

# function to print fibonacci series.
def fibonacci(terms):
    a, b = 0, 1
    for i in range(terms):
        print(a, end=", ")
        a, b = b, a + b

print("Print Fibonacci Series\n")

number_of_terms = int(input("Enter the number of terms: "))

fibonacci(number_of_terms)

print("\n\nEnd of program")
