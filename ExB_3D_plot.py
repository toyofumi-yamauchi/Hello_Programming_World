# the goal 
# plotting the motion of charged particle under static E- and B-fields 

import matplotlib.pyplot as plt
#import mpl_toolkits
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# constant
AMU = 1.66054e-27   # 1 [amu] in [kg]
dt  = 1e-10         # time step [s]
NUM_TS = 300        # the # of time step
q_e = -1.602e-19    # electron charge [C]
m_e = 9.11e-31      # electron mass [kg]
q_i = 1.602e-19     # ion charge [C]
m_i = 39.948*AMU    # ion mass [kg]
E_x = 100           # E-field in x [V/m]
E_y = 0             # E-field in y [V/m]
E_z = 0             # E-field in z [V/m]
B_x = 0             # B-field in x [V/m]
B_y = 0             # B-field in y [V/m]
B_z = 0.01          # B-field in z [V/m]
x_0 = 0             # origin in x [m]
y_0 = 0             # origin in y [m]
z_0 = 0             # origin in z [m]
u_0 = 1e5           # initial velocity in x [m/s]
v_0 = 1e5           # initial velocity in y [m/s]
w_0 = 0             # initial velocity in z [m/s]
#
q = np.zeros(2)
m = np.zeros(2)
x = np.zeros((NUM_TS,3))
y = np.zeros((NUM_TS,3))
z = np.zeros((NUM_TS,3))
u = np.zeros((NUM_TS,3))
v = np.zeros((NUM_TS,3))
w = np.zeros((NUM_TS,3))
x[0] = x_0
y[0] = y_0
z[0] = z_0
u[0] = u_0
v[0] = v_0
w[0] = w_0

for i in range(2):
    for it in range(NUM_TS-1):
        v_minus_x = u[i,it] + q[i]/m[i]*E_x*0.5*dt
        v_minus_y = v[i,it] + q[i]/m[i]*E_y*0.5*dt
        v_minus_z = w[i,it] + q[i]/m[i]*E_z*0.5*dt

        t = q[i]/m[i]*np.sqrt(B_x**2+B_y**2+B_z**2)*dt
        
        


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')