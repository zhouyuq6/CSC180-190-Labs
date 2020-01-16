# This is how my ttt class looks
# Note: Please do NOT define a T variable on its own as done previously
# Rather: define your class variables within an __init__ function as shown below

class ttt:
   def __init__(self):
      self.T=[0 for i in range(0,9)]

   # def analyzeBoard(self):
   # def genWinningMove(self,player):
   # def genNonLoser(self,player):
   # def genRandomMove(self,player):

   def Move(self,x,player):
      if self.T[x] == 0:
          self.T[x]=player
          return True
      else:
          return False

   def copy(self,source):
      if len(self.T) != len(source.T):
          return False
      else:
          for i in len(self.T):
             self.T[i]=source.T[i]
          return True


