from random import random
import numpy as np
import sympy
import random
import matplotlib.pyplot as plt

def plot_Loss():
    #generate u - v
    x = np.linspace(-1, 1, 500)
    #print(x)

    #L1 function
    y1 = abs(x)
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(x, y1, c='r')

    #L2 function
    y2 = np.square(x)
    ax.plot(x, y2, c='b')


def compute_Loss(u, v):
    if(len(u) != len(v)):
        return
    #calculate L1
    s = u - v
    l1 = 0
    for i in s:
        l1 += abs(i)
    print('L1 = ', l1)
    print('\n')

    #calculate L2
    l2 = 0
    for i in s:
        l2 = l2 + np.square(i)
    print('L2 = ', l2)
    print('\n')

def main():
    plot_Loss();

    m = random.randint(2,20)
    a = random.uniform(0, 50)
    b = random.uniform(0, 50)
    u = np.linspace(-a, a, m)
    v = np.linspace(-b, b, m)
    print('u= \n',u)
    print('\n')
    print('v= \n', v)
    print('\n')

    compute_Loss(u,v)

    plt.show()

if __name__ == "__main__":
    main()