import pandas as pd
import numpy as np

dataset = {'Name': ['A', 'B', 'c'], 'Age': [23,53,62], 'Add': ['bbsr', 'ctc', 'kpt']}

dframe = pd.DataFrame(dataset)
num_arr = dframe.to_numpy
print("Numpy array value are:", num_arr)

sr = pd.Series([34, 53, 53, 53, 43])
print(sr)
