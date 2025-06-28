import numpy as np

# Create a 1D array
array_1d = np.array([1, 2, 3, 4, 5])
print("1D Array:", array_1d)

# Create a 2D array
array_2d = np.array([[1, 2, 3], [4, 5, 6]])
print("2D Array:\n", array_2d)

# Perform basic operations
array_sum = np.sum(array_1d)
print("Sum of 1D Array:", array_sum)

array_mean = np.mean(array_2d)
print("Mean of 2D Array:", array_mean)

# Element-wise operations
squared_array = np.square(array_1d)
print("Squared 1D Array:", squared_array)

# Create an array of zeros
zeros_array = np.zeros((3, 3))
print("3x3 Zeros Array:\n", zeros_array)

# Create an array of random numbers
random_array = np.random.rand(3, 3)
print("3x3 Random Array:\n", random_array)