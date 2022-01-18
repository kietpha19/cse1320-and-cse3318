import numpy as np
import matplotlib.pyplot as plt
import random
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

def plot_projection(y , u):
    a = np.dot(y,u) / np.dot(u,u)
    projection_y = np.multiply(a,u)
    print('projection_y = ', projection_y)
    print('\n')

    z = y - projection_y

    fig = plt.figure()
    ax3d = fig.add_subplot(111, projection='3d')
    ax3d.set_xlim([-1, 20])
    ax3d.set_ylim([-1, 20])
    ax3d.set_zlim([0, 20])

    start = [0,0,0]
    ax3d.quiver(start[0], start[1], start[2], y[0], y[1], y[2])
    ax3d.quiver(start[0], start[1], start[2], u[0], u[1], u[2], color = 'g')
    ax3d.quiver(start[0], start[1], start[2], projection_y[0], projection_y[1], projection_y[2], color = 'r')
    #ax3d.quiver(start[0], start[1], start[2], z[0], z[1], z[2], color = 'r')
    #ax3d.quiver(y[0], y[1], y[2], projection_y[0], projection_y[1], projection_y[2], color = 'r')
    #ax3d.quiver(y[0], y[1], y[2], projection_y[0], projection_y[1], projection_y[2], color = 'r')
    plt.show()

def main():
    #y = [1,2,3]
    #u = [2,5,-1]


    u = np.random.rand(3)
    y = np.random.rand(3)
    u = np.multiply(20, u)
    y = np.multiply(20, y)

    plot_projection(y,u)

    

if __name__ == "__main__":
    main()