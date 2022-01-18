import scipy
import scipy.linalg as linalg
import pprint

A = scipy.array([[1,0,4],
                 [-2,3,-2],
                 [-2,0,6]])

Q, R = linalg.qr(A)

print("A =")
pprint.pprint(A)

print("Q =")
pprint.pprint(Q)

print("R =")
pprint.pprint(R)