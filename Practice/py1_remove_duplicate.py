#Remove duplicates from an integer array

def removeDuplicate(array):
    i = 0

    array.sort()

    for j in range(1,len(array)):
        if array[j] != array[i]:
            i += 1
            array[i] = nums[j]
    return i + 1

print("Remove duplicate elements from an array.\n\n")

nums = list(map(int, input("Enter the elements separated by space: ").split()))

unique_elements = removeDuplicate(nums)

print(unique_elements)
print(nums[:unique_elements])
