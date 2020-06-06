# This Python code is for myself.
''' Reference
https://qiita.com/RinGoku/items/9a0e28ddac4663cd5b03
'''

import matplotlib.pyplot as plt
import numpy as np
import random as rand

r = rand.random()
print(r)

x = np.arange(0,10.1,0.1)
y = x**2
ab_size = 101
a = np.zeros(ab_size)
b = np.zeros(ab_size)
a[0] = 0.0
b[0] = 0.0
for i in range(1,ab_size):
    a[i] = a[i-1]+0.1
    b[i] = b[i-1]+1

# figure 1
fig1 = plt.figure(1)
ax1 = fig1.add_subplot(1,1,1)
line1_xy = ax1.plot(x,y,'r',label = 'y = x^2')
line1_ab = ax1.plot(a,b,'b',label = 'b = 2*a')
ax1.set_title('Sample figure 1')
ax1.set_xlabel('x,a')
ax1.set_ylabel('y,b')
ax1.ticklabel_format(style="sci",axis="both",scilimits=(0,0))
ax1.grid()
# figure 2
fig2 = plt.figure(2)
ax2_1 = fig2.add_subplot(2,1,1)
line_xy = ax2_1.plot(x,y,'r',label = 'y = x^2')
ax2_1.set_title('Sample figure 2')
ax2_1.set_xlabel('x')
ax2_1.set_ylabel('y')
#ax2_1.set_xlim(min,max)
ax2_1.grid()
ax2_2 = fig2.add_subplot(2,1,2)
line_ab = ax2_2.plot(a,b,'b',label = 'b = 2*a')
#ax2_2.set_title('Sample figure 2-2')
ax2_2.set_xlabel('a')
ax2_2.set_ylabel('b')
ax2_2.grid()

plt.show()