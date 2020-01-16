class graph:
   def __init__(self):
      self.store=[]

   def addVertex(self,n):
      if n>=0:
         self.store=self.store+[[]]
         return len(self.store)
      else:
         return -1

   def addEdge(self,from_idx,to_idx,directed,weight):
      vert=len(self.store)
      if from_idx<0 or from_idx>=vert:
         return False
      if to_idx<0 or to_idx>=vert:
         return False
      self.store[from_idx].append([to_idx,weight])
      if directed==True:
         self.addEdge(to_idx,from_idx,False,weight)
      return True

   def traverse(self,start,typeBreadth):
      if typeBreadth==True:
         c=queue()
      else:
         c=stack()
      nostart=0
      if start==None:
         start=0
         nostart=1
      elif start<0 or start>=len(self.store):
         return []
      rval=[]
      D=[]
      P=[]
      for i in range(0,len(self.store)):
         D.append(False)
         P.append(False)
      for v in range (start,len(self.store)):
         if D[v]==False:
            c.store(v)
            D[v]=True
         while c.empty()==False:
            temp=c.retrieve()
            w=temp[1]
            adjW=self.process(w)
            if P[w]==False:   
               rval=rval+[w]
               P[w]=True
            for x in adjW:
               if D[x]==False:
                  c.store(x)
                  D[x]=True
      if nostart==1:
         rval=[rval]
      return rval
               
   def process(self,w):
      #vert in form [[1,1],[2,3]] etc
      rval=[]
      for item in self.store[w]:
         rval.append(item[0])
      return rval

   def connectivity(self,vx,vy):
      rval=[False,False]
      path=self.path(vx,vy)
      if len(path[0])>0:
         rval[0]=True
      if len(path[1])>0:
         rval[1]=True
      return rval

   def path(self,vx,vy):
      rval=[[],[]]
      if vx<0 or vx>=len(self.store):
         return rval
      if vy<0 or vy>=len(self.store):
         return rval
      rval=[[vx],[vy]]
      rval[0]=self.genPath(vx,vy,rval[0])
      rval[1]=self.genPath(vy,vx,rval[1])
      if rval[0]==[vx]:
         rval[0]=[]
      if rval[1]==[vy]:
         rval[1]=[]
      return rval

   def genPath(self,start,end,path):
      if start==end:
         return path
      potStep=self.process(start)
      for vert in potStep:
         if vert in path:
            potStep.remove(vert)

      for vert in potStep:
         path=path+[vert]
         path=self.genPath(vert,end,path)
         if path[-1]==end:
            break
         else:
            path=path[0:-1]
      return path
      
class queue:
    def __init__(self):
        self.storage=[]
        self.count = 0

    def empty(self):
       if self.count==0:
          return True
       else:
          return False

    def store(self,value):
        self.storage=self.storage+[value]
        self.count = self.count + 1
        return self.count

    def retrieve(self):
        if (self.count==0):
            return [False,0]
        else:
            r=self.storage[0]
            self.count=self.count-1
            self.storage=self.storage[1:]
            return [True,r]

class stack:
   def __init__(self):
      self.storage=[]
      self.count=0

   def empty(self):
      if (self.count==0):
         return True
      else:
         return False

   def store(self,x):
      self.storage = self.storage + [x]
      self.count = self.count + 1
      return True

   def retrieve(self):
      if (self.count==0):
         return [False,0]
      else:
         self.count = self.count - 1
         rval = self.storage[-1]
         self.storage = self.storage[0:-1]
         return [True,rval]

