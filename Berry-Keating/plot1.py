import numpy as np 
import matplotlib.pyplot as plt

a = np.loadtxt('part.dat')
f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1], label='at T = 298K')
plt.axhline(0, c='grey', alpha=0.5, ls='--')

plt.xlabel("iterations", fontsize=20)
plt.ylabel('<H>' , fontsize=20)
plt.title(r"Expectation value  of $H = \frac{1}{2}(xp + px)$ ", fontsize=20)
plt.legend()
plt.show()

f = plt.figure()
f.set_figwidth(10)
f.set_figheight(8)
plt.plot(a[:,0], a[:,1], label='at T = 298K')
plt.axhline(0, c='grey', alpha=0.5, ls='--')

plt.xlabel("iterations", fontsize=20)
plt.ylabel("<H>", fontsize=20)
plt.title(r"Expectation value  of $H = \frac{1}{2}(xp + px)$ ", fontsize=20)
plt.legend()
plt.savefig("beta.pdf")
