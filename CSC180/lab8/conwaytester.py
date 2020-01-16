from conwaylib import *

m=conway(10,12,'zeros')
r=m.getDisp()
t=m.printDisp()
for i in range(0,10):
	m.setPos(i,0,1)
	m.setPos(i,11,1)
for j in range(0,12):
	m.setPos(0,j,1)
	m.setPos(9,j,1)
m.printDisp()

for i in range(0,10):
	for j in range(0,2):
		m.setPos(i,j+i,1)

m.printDisp()

print m.getNeighbours(0,0)
