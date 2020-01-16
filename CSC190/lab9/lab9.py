def hanoi(n,start,tmp,final):
   if n>0:
      hanoi(n-1,start,final,tmp)
      final.append(start.pop()) 
      hanoi(n-1,tmp,start,final)
      print start,tmp,final
      return True
   else:
      return True

def quicksort(u,ini,fin):
   if ini < fin:
      pIndex = partition(u,ini,fin)
      quicksort(u,ini,pIndex-1)
      quicksort(u,pIndex+1,fin)
   return True

def quick_sort(u,ini,fin):
   if ini < fin:
      pIndex = partition(u,ini,fin)
      quick_sort(u,ini,pIndex-1)
      quick_sort(u,pIndex+1,fin)
   return True

def partition(u,ini,fin):
   pivot=u[fin]
   i=ini-1
   tmp=0
   for j in range(ini,fin):
      if (u[j]<=pivot):
         i=i+1
         tmp=u[i]
         u[i]=u[j]
         u[j]=tmp
   tmp=u[i+1]
   u[i+1]=u[fin]
   u[fin]=tmp
   return i+1


