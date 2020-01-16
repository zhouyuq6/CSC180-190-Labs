class stack:
   def __init__(self,initList):
      self.store=[]
      if (initList==[]):
         return False
      for i in range(0,len(initList)):
         self.store.append(initList[i])
      print self.store

   def push(self,dataIn):
      self.store=[dataIn]+self.store
      return True

   def pop(self):
      if (self.store==[]):
         print "The stack is empty"
         return False
      else:
         rval=self.store[0]
         self.store=self.store[1:]
         return rval
