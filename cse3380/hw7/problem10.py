import numpy as np
import sympy
import scipy.linalg as linalg

""" the dimension of the set equal to the number of pivot colums
first, I compute the row reduce echolon matirx using sympy
then, the dimesion of the set is the length of the pivot array
second, the columns consist of pivot point form the basis for the set
so, I print our the column that have pivot point for the basis
"""
#create matrix A
A = np.array([
    [0,2,3],
    [1,1,-2],
    [4,1,0],
    [3,-1,-1]
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
print('A_rref = \n', A_rref)
print('\n')

print('the dimension of the following set is: ', len(pivot))
print('\n')

print('the basis of the set is the set of these vectors: \n')
for i in pivot:
    print(np.array(A[:, i]).T)
