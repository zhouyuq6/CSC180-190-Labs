from graph import *

x=graph()
x.addVertex(1)
x.addVertex(1)
x.addVertex(1)
x.addVertex(1)
x.addVertex(1)
print x.store
x.addEdge(0,1,False,1)
x.addEdge(0,2,False,1)
x.addEdge(0,3,False,1)
x.addEdge(1,2,False,2)
x.addEdge(1,4,False,2)
x.addEdge(2,3,True,3)
x.addEdge(3,4,True,4)
x.addEdge(4,5,True,5)
print x.store
print "Depth"
print x.traverse(0,False)
print "Breadth"
print x.traverse(0,True)
print "Breadth; start=None"
print x.traverse(None,True)
print x.connectivity(2,4)
print x.path(3,4)
