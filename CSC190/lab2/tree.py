import binary_tree

class tree:
   def __init__(self,x):
      self.store = [x,[]]
      self.level = 0
      self.space = "   "    

   def AddSuccessor(self,x):
      self.store[1] = self.store[1] + [x]
      last=len(self.store[1])-1
      self.store[1][last].level=self.level+1
      return True

   def Print_DepthFirst(self):
      print self.level*self.space+str(self.store[0])
      for i in range(0,len(self.store[1])):
         self.store[1][i].Print_DepthFirst()
      return True

   def Get_LevelList(self,num):
      rval=[]
      if self.level==num:
          rval=[self.store[0]]+rval
      elif self.level<num:
          for item in self.store[1]:
             rval=rval+item.Get_LevelList(num)
      return rval

   def Get_LevelOrder(self):
      rval=[]
      i=0
      while(len(self.Get_LevelList(i))!=0):
         rval=rval+self.Get_LevelList(i)
         i=i+1
      return rval

   def ConvertToBinaryTree(self):
      i=1
      levelList=[]
      if len(self.store)==0:
         return False
      biTree=binary_tree.binary_tree(self.store[0])
      while(len(self.Get_LevelList(i))!=0):
         levelList=levelList+[self.Get_LevelList(i)]
         i=i+1
      biTree.buildLevel(levelList)
      return biTree

   def buildBranch(self,treeList):
      if (len(treeList)==0):
         return True
      elif(len(treeList)>=1):
         sublist=treeList[0]
         print sublist
         treeList=treeList[1:]
         for i in range (0,len(sublist)):
            node=tree(sublist[i])
            self.AddSuccessor(node)
         return self.store[1][0].buildBranch(treeList)

         



