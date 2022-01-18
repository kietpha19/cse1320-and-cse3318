from random import random
import numpy as np
import sympy
import random
import matplotlib.pyplot as plt

def norms_product(u, v):
    return np.sqrt(np.dot(u,u)) * np.sqrt(np.dot(v,v))

def cosine_similar(A):
    print('A =\n', A)
    print('\n')

    A_transpose = A.transpose()
    print('A_transpose =\n', A_transpose);
    print('\n')

    A_dot_product = A @ A_transpose
    print('A_dot_product = \n', A_dot_product)
    print('\n')
    
    A_norm = []

    for i in A:
        for j in A:
            A_norm.append(norms_product(i, j))

    A_norm = np.reshape(A_norm, (len(A), len(A)))
    print('A_norm = \n',A_norm)
    print('\n')

    A_cosine = []
    for i in range(len(A)):
        for j in range(len(A)):
            A_cosine.append(A_dot_product[i][j] / A_norm[i][j]);

    A_cosine = np.reshape(A_cosine, (len(A), len(A)))
    print('A_cosine = \n', A_cosine)
    print('\n')

    return A_cosine
            

def main():
    
    m = random.randint(2,20)
    n = random.randint(2,20)
    
    #A = np.random.randint(-50, 50, (m,n))
    #A_cosine = cosine_similar(A)

    B = np.random.uniform(-50., 50., (m,n))
    A_cosine = cosine_similar(B)

    plt.matshow(A_cosine)
    plt.show()

if __name__ == "__main__":
    main()


