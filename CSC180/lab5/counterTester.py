from counterlib import *

x = counter(100)
y = counter(300)
z = counter(0)
p = counter(200000)

x.evolve(10)
for i in range(0,100,10):
	y.evolve(i)
z.evolve(200)
z.evolve(-10)
p.evolve(99999)

print x.getState()
print y.getState()
print z.getState()
print p.getState()
