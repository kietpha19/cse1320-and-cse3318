import numpy as np
import scipy.linalg as linalg


def map_to_std_coord(B, xB):
    """ coordinate of x in standard coordinate system is
    simply equal to matrix make by colums of basis B times xB """
    x = B @ xB
    print("vector x\n", x)

def main():
    B = np.array([
        [0,-4,6],
        [-1,0,6],
        [-1,0,3]
    ])
    print('matrix B\n', B)
    xB = np.array([
        [-2],
        [6],
        [1]
    ])
    print('vector x in B\n', xB)
    map_to_std_coord(B, xB)

if __name__ == "__main__":
    main()