from stackLib import *

listA=[1,2,3,4,5]
s=stack(listA)
for i in range(9,5,-1):
   s.push(i)
print s.store
print "start poping"
i=0
while(True):
   a=s.pop()
   print "#"+str(i)+" "
   print a
   print s.store
   if (a==False):
      break
   i=i+1

