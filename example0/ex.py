import numpy as np
import example

a = np.ones((10,3))
b = np.ones((10,3))*3
c = example.add_arrays(a, b)

print(c)
