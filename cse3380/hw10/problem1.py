from random import random
import numpy as np
import random

# a) generate random matrix
m = 0
n = 0
while( m == n):
    m = random.randint(2,20)
    n = random.randint(2,20)

X = np.random.uniform(-50., 50., (n,m))
X = np.matrix.round(X, decimals=5, out=None)
print('X= ')
print(X)

# b) compute eigendecompostion of matrix X^t*X
X_transpose = np.transpose(X)
A = np.dot(X_transpose, X)

###################################
# debugging matrix
# X = np.array([
#     [4,11,14],
#     [8,7,-2]
# ])
# X_transpose = np.transpose(X)
# #A = np.dot(X_transpose, X)
# A = X_transpose @ X
# print('X = ')
# print(X)
#####################################

A = np.matrix.round(A, decimals=5, out=None)
print('X_transpose * X = ')
print(A)

W, V= np.linalg.eig(np.array(A))
W = np.matrix.round(W, decimals=5, out=None)
V = np.matrix.round(V, decimals=5, out=None)
print('W = ')
print(W)
print('V = ')
print(np.transpose(V))

# c) project the computed eigenvectors onto the data via matrix multiplication and normalize them so that the vectors are of length 1
N = np.array([])
for v in V:
    z = np.dot(X,v)
    z = z/np.sqrt(np.sum(z**2))
    N = np.append(N,z, axis=0)

N = np.reshape(N, (len(X[0]), len(X)))
N = np.matrix.round(N, decimals=5, out=None)
print('N = ')
print(np.transpose(N))

# d) compute the singular value decompositionof the matrix X
u,s,v = np.linalg.svd(X, full_matrices=False)

print('U = ')
print(u)
print('S = ')
print(s)
print('V = ')
print(v)

"""
the span of Col U vector and the span of eigenvectos form step C are equal. 
"""