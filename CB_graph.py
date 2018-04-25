import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('advection.txt')
plt.figure()
plt.plot(datos[:,0], datos[:,1], label = 'Valor Inicial')
plt.plot(datos[:,0], datos[:,2], label = 'snapshot2')
plt.plot(datos[:,0], datos[:,3], label = 'snapshot3')
plt.plot(datos[:,0], datos[:,4], label = 'snapshot4')
#plt.plot(datos[:,0], datos[:,5], label = 'snapshot5')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Advection')

plt.savefig('advection.pdf')
