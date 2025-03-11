#Create a python function that checks whether a given string is a palindrome.

#function to check palindrom
def isPalindrome(string):
    length = len(string)

    for i in range(length // 2):
        if string[i] != string[-(i + 1)]:
            return False
    return True


string = input("Enter a string to check for Palindrome: ")

if isPalindrome(string):
    print(string, "is a palindrome.")
else:
    print(string, "is not a palindrome.")
