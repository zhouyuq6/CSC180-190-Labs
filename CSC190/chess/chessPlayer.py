from chessPlayer_move import *
from random import randint
from chessPlayer_tree import *

def genMove(board,player):
   L=GetPlayerPositions(board,player)
   rval=[]
   for pos in L:
      moves=GetPieceLegalMoves(board,pos)
      for i in moves:
         if not(IsPositionUnderThreat(board,i,player)):
            can=[pos,i]
            rval.append(can)
   return rval

def randomMove(board,player):
   mList=genMove(board,player)
   move=randint(0,len(mList)-1)
   return mList[move]

def mmMove(board,player,level):
   bestval=-999.9
   bestmove=[]
   canM=[]
   canMoves=[]
   rval=[]
   fakeboard=board[:]
   T=evaltree(fakeboard,player)
   treeBuild(T,level)
   T.updateVal(level)
   mList=genMove(T.b,player)
   #generate return value
   for child in T.c:
      num=T.c.index(child)
      value=child.v
      canM=[mList[num],value]
      canMoves=canMoves+[canM] 
      if bestval<value:
         bestval=value
         bestmove=[num]
      elif (bestval==value):
         if len(bestmove)!=0:
            bestmove.append(num)
   if len(bestmove)==0:
      move=randomMove(board,player)
      canMoves=[[move,0.0]]
   elif len(bestmove)==1:
      bmove=bestmove[0]
   else:
      bmove=randint(0,len(bestmove)-1)
   #rval=[True,move,canMoves,evalTree]
   move=mList[bmove]
   rval=[move,canMoves,T]
   return rval

def treeBuild(tree,level):
   board=tree.b[:]
   depth=tree.d
   if depth%2==0: 
      player=tree.py
   elif depth%2==1: 
      player=30-tree.py
   m=genMove(board,player)
   tree.addChild(m)
   if level!=0:
      childList=tree.c
      for child in childList:
         treeBuild(child,level-1)
   return True

def chessPlayer(board,player):
   rval=[]
   rMove=mmMove(board,player,3)
   if len(rMove)==0:
      rval=[False,[],[],[]]
      return rval
   evalTree=rMove[2]
   evalList=GetLevelOrder(evalTree)
   rval=[True,rMove[0],rMove[1],evalList]
   return rval
  
def GetLevelOrder(tree):
   x=queue()
   x.enqueue([tree])
   accum=[]
   v=[]
   while True:
      y=x.dequeue()
      if (y[0]==False):
         break
      else:
         v=y[1]
         for i in v:
            accum=accum+[i.v]
            if len(accum)>256:
               break
            x.enqueue(i.c)
   return accum
