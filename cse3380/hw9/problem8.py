from matplotlib import colors
import numpy as np
import numpy.linalg as linalg
import matplotlib.pyplot as plt

A = np.array([[1,-2],
             [-4,1]])

w, v = linalg.eig(A)

#W = np.array(W)
print(w)
print(v)

fig = plt.figure()
plt.ylabel('Y-axis')
plt.xlabel('X-axis')
ax = plt.gca()
ax.set_xlim([-3, 2])
ax.set_ylim([-5, 2])
ax.quiver(0,0, A[0][0], A[1][0], color='r', angles ='xy', scale_units='xy', scale=1)
ax.quiver(0,0, A[0][1], A[1][1], color='r', angles ='xy', scale_units='xy', scale=1)
ax.quiver(0,0, v[0][0], v[1][0], color='b', angles ='xy', scale_units='xy', scale=1)
ax.quiver(0,0, v[0][1], v[1][1], color='b', angles ='xy', scale_units='xy', scale=1)
plt.draw()
plt.show()