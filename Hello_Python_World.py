# 04-11-2020
# Reference: https://qiita.com/RinGoku/items/9a0e28ddac4663cd5b03

import matplotlib.pyplot as plt
import numpy as np

x = np.array([1,2,3,4])
y = np.array([2,3,4,5])
plt.plot(x,y)
plt.show()

X = np.arange(0,10,0.1)
Y = 4 ** X
plt.title("Exponential function to the base 4")
plt.xlabel("X")
plt.ylabel("Y")
plt.plot(X,Y)
plt.show()