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
   for i in range(len(u)-1,-1,-1):
      childIdx=len(u)
      if (i*2+1)>=len(u):
         continue
      elif (i*2+2)>=len(u):
         childIdx=i*2+1
      else:
         childIdx=u.index(max(u[i*2+1],u[i*2+2]))
      if not childIdx>=len(u):
         if u[i]<u[childIdx]:
            swap(u,i,childIdx)
   return True

def reheapify(u,end):
   i=0
   childIdx=0
   while i<end:
      if (i*2+1)>=end:
         break
      elif (i*2+2)>=end:
         childIdx=i*2+1
      else:
         childIdx=u.index(max(u[i*2+1],u[i*2+2]))

      if u[i]<u[childIdx]:
         swap(u,i,childIdx)
         i=childIdx
      else:
         break
   return 0

def heap_sort(u):
   i=0
   end=len(u)-1
   heapify(u)
   for i in range(0,len(u)):
      swap(u,0,end)
      reheapify(u,end)
      end=end-1
   return True

def merge_sort(u):
   if len(u)<=1:
      return True
   else:
      ul=u[0:len(u)/2]
      uh=u[len(u)/2:]
      merge_sort(ul)
      merge_sort(uh)
   merge(u,ul,uh)
   return True

def merge(u,a,b):
   ia=0
   ib=0
   na=len(a)
   nb=len(b)
   n=na+nb
   for i in range(0,n):
      if ia>=na:
         u[i:]=b[ib:]
         break
      elif ib>=nb:
         u[i:]=a[ia:]
         break
      if a[ia]<b[ib]:
         u[i]=a[ia]
         ia=ia+1
         continue
      if a[ia]>b[ib]:
         u[i]=b[ib]
         ib=ib+1
         continue 
   return True


def quick_sort(u,ini,fin):
  if ini<fin:
     pIndex=partition(u,ini,fin)
     quick_sort(u,ini,pIndex-1)
     quick_sort(u,pIndex+1,fin)
  return True  

def partition(u,ini,fin):
   pivot=u[fin]
   i=ini+1
   j=fin
   swapped=False
   while not swapped:
      while (i<=j) and (u[i]<=pivot):
         i=i+1
      while (u[j]<=pivot) and (j>=i):
         j=j-1
      if j<i:
         swapped=True
      else:
         temp=u[i]
         u[i]=u[j]
         u[j]=u[i]

   temp=u[ini]
   u[ini]=u[j]
   u[j]=temp

   return j


v1=[100,2,1,3,4,16,5,6,8,10]
v2=[100,2,1,3,4,16,5,6,8,10]
print "before merge",v1
merge_sort(v1)
print "after merge",v1

print "before merge",v2
heap_sort(v2)
print "after merge",v2

