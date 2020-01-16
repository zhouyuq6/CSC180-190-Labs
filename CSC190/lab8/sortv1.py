def selection_sort(u):
   for i in range(0,len(u),1):
      minidx=i
      for j in range(i+1,len(u)):
         if (u[j]<u[minidx]):
            minidx=j
      swap(u,i,minidx)
   return True

def swap(u,i,j):
   if len(u)<=i or len(u)<=j:
      return False
   temp=u[i]
   u[i]=u[j]
   u[j]=temp
   return True

def heapify(u):
   for i in range(0,len(u)):
      childIdx=
      if u[i]<u[i*2+1]:
         swap(u,i,i*2+1)
        


v1=[10,9,8,7,6,5,4,3,2,1,0]
print "before",v1
selection_sort(v1)
print "after",v1
