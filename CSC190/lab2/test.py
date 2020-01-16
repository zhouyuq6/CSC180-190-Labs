from tree import *
from binary_tree import *

print "----general tree----\n"

x=tree.tree(10)
y=tree.tree(2000)
z=tree.tree(3000)
x.AddSuccessor(y)
x.AddSuccessor(z)
c=tree.tree(5)
d=tree.tree(30)
e=tree.tree(25)
y.AddSuccessor(c)
y.AddSuccessor(c)
y.AddSuccessor(d)
z.AddSuccessor(d)
d.AddSuccessor(e)

x.Print_DepthFirst()
print x.Get_LevelOrder()

print "\n----Converting to binary tree----"
btree=x.ConvertToBinaryTree()
btree.Print_DepthFirst()
print btree.Get_LevelOrder()

print "\n----binary tree----"

a=binary_tree(1000)
b=binary_tree(2000)
c=binary_tree(3000)
j=binary_tree(400)
k=binary_tree(500)
l=binary_tree(600)
f=binary_tree(70)
g=binary_tree(80)
a.AddLeft(b)
a.AddRight(c)
b.AddLeft(j)
b.AddRight(k)
c.AddLeft(l)
k.AddLeft(f)
l.AddRight(g)
print "left up, right down\n"
a.Print_DepthFirst()
print a.Get_LevelOrder()

print "\n----Converting to tree----"
tree=btree.ConvertToTree()
print tree
print tree[1].Get_LevelOrder()




