def cumulativesum(array):
    result = []
    sum = 0
    for num in array:
        sum += num
        result.append(sum)
    return result

array_size = int(input("Enter the number of elements:"))
demo_arr = []

for i in range(array_size):
    num = int(input())
    demo_arr.append(num)

min_value = min(demo_arr)
max_value = max(demo_arr)

sum_value = sum(demo_arr)

new_array = cumulativesum(demo_arr)

print(new_array)
