import pandas as pd

def maximum(arr):
	max = arr[0]
	for i in range(1, len(arr)):
		if arr[i] > max:
			max = arr[i]
	return max

def minimum(arr):
	min = arr[0]
	for i in range(1, len(arr)):
		if arr[i] < min:
			min = arr[i]
	return min
def addition(arr):
	sum = 0
	for i in range(len(arr)):
		sum += arr[i]
	return sum


list_1 = [ 34, 54,45,54,34,76,45]
arr = pd.array(list_1)

max_value = maximum(arr)
min_value = minimum(arr)
cumulative_sum = addition(arr)

print(max_value)
print(min_value)
print(cumulative_sum)
