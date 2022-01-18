import numpy as np
import numpy.linalg as linalg
import matplotlib.pyplot as plt


D = np.loadtxt("dataset2.txt")
#print(D)

A = [[0 for i in range(3)] for j in range(len(D))]
x = [0]*len(D)
y = [0]*len(D)

for i in range(len(D)):
    A[i][0] = np.square(D[i][0])
    A[i][1] = D[i][0]
    A[i][2] = 1
    x[i] = D[i][0]
    y[i] = D[i][1]


x = np.array(x)
y = np.array(y)
#print(x)

a,b,c = linalg.lstsq(A, y, rcond=None)[0]

_ = plt.plot(x, y, 'o', label='Original data', markersize=5)
_ = plt.plot(x, a*x*x + b*x + c, 'r', label='Fitted line')
_ = plt.legend()
plt.show()



