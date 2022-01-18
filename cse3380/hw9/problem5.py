import numpy as np
import numpy.linalg as linalg
import matplotlib.pyplot as plt

D = np.loadtxt("dataset1.txt")
#print(D)
x = [0]*len(D)
y = [0]*len(D)
for i in range(len(D)):
    x[i] = D[i][0]
    y[i] = D[i][1]

x = np.array(x)
y = np.array(y)
print(y)
A = np.vstack([x, np.ones(len(x))]).T
m, c = linalg.lstsq(A, y, rcond=None)[0]

_ = plt.plot(x, y, 'o', label='Original data', markersize=5)
_ = plt.plot(x, m*x + c, 'r', label='Fitted line')
_ = plt.legend()
plt.show()



