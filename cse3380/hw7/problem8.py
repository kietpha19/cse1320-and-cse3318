import numpy as np
import sympy
import scipy.linalg as linalg

#create matrix A
A = np.array([
    [3, 8, -5],
    [3,-6,-7],
    [3, 4, 2]
])
print('A =\n', A)
print('\n')

#convert the numpy array to the sympy.Matrix class
A_sympy = sympy.Matrix(A)
print(A_sympy)
print('\n')

#calculate the RREF of A
A_rref = A_sympy.rref()
print('A_rref (from sympy):\n', A_rref)
print('\n')

#save the pivot columns
pivot = A_rref[1]
print('pivot\n', pivot)

#convert A_rref to numpy
A_rref = np.array(A_rref[0].tolist())
print('A_rref =\n', A_rref);
print('\n')

#calculate column space of A
A_transpose = np.transpose(A);
# print('A_transpose\n', A_transpose)
ColA = ([])
for i in pivot:
   ColA.append(A_transpose[i]);

ColA = np.transpose(ColA)
print('Col A = span of\n')
for i in pivot:
    print(np.array(A[:, i]).T)
print('\n')
print('or if write in term of a matrix with column space')
print('Col A = \n', ColA)
print("\n")

#solve the matrix equation Ax = b
b = np.array([[-1],[-1],[3]])
print('b vector\n', b)
x = linalg.solve(A , b)
print('solved x vector\n', x)
print('A@x =\n', A@x)
print('\n')

#compute the null space of A
NulA = linalg.null_space(A);
print('Null space\n', NulA);

