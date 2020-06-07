# the goal 
# plotting the motion of charged particle under E- and B-fields 

import matplotlib.pyplot as pyplot
#import mpl_toolkits
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# constant
AMU = 1.66054e-27   # 1 [amu] in [kg]
q_e = -1.602e-19    # electron charge [C]
m_e = 9.11e-31      # electron mass [kg]
q_i = 1.602e-19     # ion charge [C]
m_i = 39.948*AMU    # ion mass [kg]
NUM_TS = 300

E = np.zeros(3)
x = np.zeros((NUM_TS,3))
v = np.zeros((NUM_TS,3))
