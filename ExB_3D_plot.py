# the goal 
# plotting the motion of charged particle under static E- and B-fields 

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# time setting
dt  = 1e-10         # time step [s]
NUM_TS = 150        # the # of time step

# particle information
AMU = 1.66054e-27   # 1 [amu] in [kg]
q_e = -1.602e-19    # electron charge [C]
m_e = 9.11e-31      # electron mass [kg]
q_i = 1.602e-19     # ion charge [C]
#m_i = 40*AMU    # ion mass [kg]
m_i = m_e           # positron mass [kg]
q = [q_e, q_i]
m = [m_e, m_i]

# field information
E_x = 100           # E-field in x [V/m]
E_y = 0           # E-field in y [V/m]
E_z = 0             # E-field in z [V/m]
B_x = 0             # B-field in x [V/m]
B_y = 0             # B-field in y [V/m]
B_z = 0.01          # B-field in z [V/m]
v_drift = np.sqrt(E_x**2+E_y**2+E_z**2)/np.sqrt(B_x**2+B_y**2+B_z**2)

# position/velocity information
x_0 = 0             # origin in x [m]
y_0 = 0             # origin in y [m]
z_0 = 0             # origin in z [m]
u_0 = 0             # initial velocity in x [m/s]
v_0 = 1e5           # initial velocity in y [m/s]
w_0 = 0             # initial velocity in z [m/s]
x = np.zeros((2,NUM_TS))
y = np.zeros((2,NUM_TS))
z = np.zeros((2,NUM_TS))
u = np.zeros((2,NUM_TS))
v = np.zeros((2,NUM_TS))
w = np.zeros((2,NUM_TS))
x[:,0] = x_0
y[:,0] = y_0
z[:.0] = z_0
u[:,0] = u_0
v[:,0] = v_0
w[:,0] = w_0

# loop
for i in range(2):
    for it in range(NUM_TS-1):
        u_minus = u[i,it] + q[i]/m[i]*E_x*0.5*dt
        v_minus = v[i,it] + q[i]/m[i]*E_y*0.5*dt
        w_minus = w[i,it] + q[i]/m[i]*E_z*0.5*dt

        t_x = q[i]*dt/m[i]/2.0*B_x
        t_y = q[i]*dt/m[i]/2.0*B_y
        t_z = q[i]*dt/m[i]/2.0*B_z

        u_prime = u_minus + (v_minus*t_z - w_minus*t_y)
        v_prime = v_minus + (w_minus*t_x - u_minus*t_z)
        w_prime = w_minus + (u_minus*t_y - v_minus*t_x)

        s_x = 2*t_x/(1+(t_x**2 + t_y**2 + t_z**2))
        s_y = 2*t_y/(1+(t_x**2 + t_y**2 + t_z**2))
        s_z = 2*t_z/(1+(t_x**2 + t_y**2 + t_z**2))

        u_plus = u_minus + (v_prime*s_z - w_prime*s_y)
        v_plus = v_minus + (w_prime*s_x - u_prime*s_z)
        w_plus = w_minus + (u_prime*s_y - v_prime*s_x)

        u[i,it+1] = u_plus + q[i]/m[i]*E_x*0.5*dt        
        v[i,it+1] = v_plus + q[i]/m[i]*E_y*0.5*dt
        w[i,it+1] = w_plus + q[i]/m[i]*E_z*0.5*dt

        x[i,it+1] = x[i,it] + u[i,it+1]*dt
        y[i,it+1] = y[i,it] + v[i,it+1]*dt
        z[i,it+1] = z[i,it] + w[i,it+1]*dt

max_range = np.array([x.max()-x.min(), y.max()-y.min(), z.max()-z.min()]).max()*0.5
mid_x = (x.max() + x.min())*0.5
mid_y = (y.max() + y.min())*0.5
mid_z = (z.max() + z.min())*0.5

print('m_ion/m_electron: %.4g'%(m_i/m_e))
print('Simulated time  : %.4g [s]'%(dt*NUM_TS))
print('Drift velocity  : %.4g [m/s]'%v_drift)

# 3D plotting
fig_3D = plt.figure(1)
ax_3D = fig_3D.add_subplot(111, projection='3d')
ax_3D.plot(x[0,:],y[0,:],z[0,:],label='electron')
ax_3D.plot(x[1,:],y[1,:],z[1,:],label='ion')
ax_3D.set_title('3D plotting')
ax_3D.set_xlabel('x [m]')
ax_3D.set_ylabel('y [m]')
ax_3D.set_zlabel('z [m]')
ax_3D.legend()
ax_3D.axis('equal')
ax_3D.ticklabel_format(style="sci",axis="x",scilimits=(0,0))
ax_3D.ticklabel_format(style="sci",axis="y",scilimits=(0,0))
ax_3D.ticklabel_format(style="sci",axis="z",scilimits=(0,0))
ax_3D.set_xlim(mid_x - max_range, mid_x + max_range)
ax_3D.set_ylim(mid_y - max_range, mid_y + max_range)
ax_3D.set_zlim(mid_z - max_range, mid_z + max_range)


# 2D plotting
fig_2D = plt.figure(2)

ax_xy = fig_2D.add_subplot(211)
ax_xy.plot(x[0,:],y[0,:],label='electron')
ax_xy.plot(x[1,:],y[1,:],label='ion')
ax_xy.set_title('XY plane')
ax_xy.set_xlabel('x [m]')
ax_xy.set_ylabel('y [m]')
ax_xy.legend()
ax_xy.axis('equal')
ax_xy.ticklabel_format(style="sci",axis="x",scilimits=(0,0))
ax_xy.ticklabel_format(style="sci",axis="y",scilimits=(0,0))
ax_xy.set_xlim(mid_x - max_range, mid_x + max_range)
ax_xy.set_ylim(mid_y - max_range, mid_y + max_range)
ax_xy.grid()

ax_yz = fig_2D.add_subplot(223)
ax_yz.plot(y[0,:],z[0,:],label='electron')
ax_yz.plot(y[1,:],z[1,:],label='ion')
ax_yz.set_title('YZ plane')
ax_yz.set_xlabel('y [m]')
ax_yz.set_ylabel('z [m]')
ax_yz.legend()
ax_yz.axis('equal')
ax_yz.ticklabel_format(style="sci",axis="x",scilimits=(0,0))
ax_yz.ticklabel_format(style="sci",axis="y",scilimits=(0,0))
ax_yz.set_xlim(mid_y - max_range, mid_y + max_range)
ax_yz.set_ylim(mid_z - max_range, mid_z + max_range)
ax_yz.grid()

ax_xz = fig_2D.add_subplot(224)
ax_xz.plot(x[0,:],z[0,:],label='electron')
ax_xz.plot(x[1,:],z[1,:],label='ion')
ax_xz.set_title('XZ plane')
ax_xz.set_xlabel('x [m]')
ax_xz.set_ylabel('z [m]')
ax_xz.legend()
ax_xz.axis('equal')
ax_xz.ticklabel_format(style="sci",axis="x",scilimits=(0,0))
ax_xz.ticklabel_format(style="sci",axis="y",scilimits=(0,0))
ax_xz.set_xlim(mid_x - max_range, mid_x + max_range)
ax_xz.set_ylim(mid_z - max_range, mid_z + max_range)
ax_xz.grid()

plt.show()