import tree

class binary_tree:
   def __init__(self,x):
      self.store=[x,[],[]]
      self.level=0
      self.space = "   "  

   def AddLeft(self,x):
      self.store[1]=self.store[1]+[x]
      last=len(self.store[1])-1
      self.store[1][last].level=self.level+1
      return True

   def AddRight(self,x):
      self.store[2]=self.store[2]+[x]
      last=len(self.store[2])-1
      self.store[2][last].level=self.level+1
      return True

   def Print_DepthFirst(self):
      for i in range(0,len(self.store[1])):
         self.store[1][i].Print_DepthFirst()
      print self.level*self.space+str(self.store[0])
      for i in range(0,len(self.store[2])):
         self.store[2][i].Print_DepthFirst()
      return True

   def Get_LevelList(self,num):
      rval=[]
      if self.level==num:
          rval=[self.store[0]]+rval
      elif self.level<num:
          for i in range(1,3):
             for item in self.store[i]:
                rval=rval+item.Get_LevelList(num)
      return rval

   def Get_LevelOrder(self):
      rval=[]
      i=0
      while(len(self.Get_LevelList(i))!=0):
         rval=rval+self.Get_LevelList(i)
         i=i+1
      return rval

   def buildBiBranch(self,sublevelList):
      if len(sublevelList)==0:
         return True
      elif(len(sublevelList)>=1):
         node=binary_tree(sublevelList[0])
         self.AddRight(node)
         if(len(sublevelList)>1): 
            sublevellist=sublevelList[1:]
            return self.store[2][0].buildBiBranch(sublevellist)
         return True
      else:
         return False

   def buildLevel(self,levelList):
      sublist=[]
      i=0
      if len(levelList)==0:
         return True
      else:
         for i in range(0,len(levelList[0])):
            sublist=sublist+[levelList[0][i]]
         bi=binary_tree(sublist[0])
         sublist=sublist[1:]
         self.AddLeft(bi)
         bi.buildBiBranch(sublist)
         levelList=levelList[1:]
      return self.store[1][0].buildLevel(levelList)

   def ConvertToTree(self):
       rval=[True]
       treelist=[]
       rtree=tree.tree(self.store[0])
       if len(self.store[2])!=0:
          rval[0]=False
       treelist=self.saveBiTree(treelist)
       print treelist
       rtree.buildBranch(treelist)
       rval=rval+[rtree]
       return rval

   def saveLevel(self,level):
      if len(self.store[2])==0:
         level=level+[self.store[0]]
      else:
         level=level+[self.store[0]]
         return self.store[2][0].saveLevel(level)
      return level

   def saveBiTree(self,treeList):
      sublist=[]
      if len(self.store[1])==0:
         sublist=self.saveLevel(sublist)
         treeList=treeList+[sublist]
      else:
         sublist=self.saveLevel(sublist)
         print sublist
         treeList=treeList+[sublist]
         return self.store[1][0].saveBiTree(treeList)
      return treeList

      
