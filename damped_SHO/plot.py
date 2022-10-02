import numpy as np 
import matplotlib.pyplot as plt

a = np.loadtxt("main.dat")

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1])
plt.xlim([0,100])
plt.xlabel("iterations", fontsize=20)
plt.ylabel("<H>", fontsize=20)
plt.title("Expectation value of H= p^2/2*m + (1/2)m*(omega^2)*(x^2) - p/m", fontsize=20)
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1])
plt.xlim([0,100])
plt.xlabel("iterations", fontsize=20)
plt.ylabel("<H>/N^2", fontsize=20)
plt.title("Expectation value of H= p^2/2*m + (1/2)m*(omega^2)*(x^2) - p/m", fontsize=20)
plt.savefig("main.pdf")