import numpy as np 
import matplotlib.pyplot as plt

a = np.loadtxt("main.dat")

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,2], label='<H>')
plt.axhline(0, c='grey', alpha=0.5, ls='--')
plt.xlim([0,100])
plt.xlabel("iterations", fontsize=20)
plt.ylabel("<H>", fontsize=20)
plt.title("Expectation value of H= p^2/2*m + (1/2)m*(omega^2)*(x^2) - p/m", fontsize=20)
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,2], label='<H>')
plt.axhline(0, c='grey', alpha=0.5, ls='--')
plt.xlim([0,100])
plt.xlabel("iterations", fontsize=20)
plt.ylabel("<H>", fontsize=20)
plt.title("Expectation value of H= p^2/2*m + (1/2)m*(omega^2)*(x^2) - p/m", fontsize=20)
plt.legend()
plt.savefig("main.pdf")