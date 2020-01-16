def genBoard():
   board=[0]*64
   board[0:8]=[13,11,12,15,14,12,11,13]
   board[8:16]=[10]*8
   board[56:64]=[23,21,22,25,24,22,21,23]
   board[48:56]=[20]*8
   return board

def printHelp(board):
   for i in range(63,-1,-1):
      if(((i+1)%8)==0):
         print '\n'+'row'+str(i/8),
      if (board[i]!=0):
         print board[i],
      else:
         print str(board[i])+' ',
   print '\n'
   return True

def GetPlayerPositions(board,player):
    rval=[]
    player=player/10
    for i in range(0,64):
       if (board[i]/10==player):
          rval.append(i)
    if rval==[]:
       return False
    else:
       return rval

def GetPieceLegalMoves(board,position):
   if board[position]==0:
      print "ERR:No piece in this position"
      return False
   pos=position
   piece=board[pos]
   player=(piece/10)
   if (piece%10==0):#Pawn
      rval=isEmpty(pawnMove(board,pos),board,player)
   elif (piece%10==3):#Rook
      rval=rookBreak(rookMove(pos),board,pos)
   elif (piece%10==1):#Knight
      rval=isEmpty(knightMove(pos),board,player)
   elif (piece%10==2):#Bishop
      rval=bishopBreak(bishopMove(pos),board,pos)
   elif (piece%10==4):#Queen
      rval=rookBreak(rookMove(pos),board,pos)+bishopBreak(bishopMove(pos),board,pos)
   elif (piece%10==5):#King
      rval=isEmpty(kingMove(pos),board,player)
   else:
      print "ERR:Unknown piece"
   return rval

def isEmpty(move,board,py):
   rval=[]
   for item in move:
      if (board[item]/10)!=py:
         rval.append(item)
   return rval

def onBoard(moves):
   rval=[]
   for item in moves:
      if item>-1 and item<64:
         rval.append(item)
   return rval

def pawnMove(board,pos):
   row=pos/8
   col=pos%8
   rval=[]
   player=board[pos]/10
   oppo=3-player 
   if player==1: #white
      if row==7:
         return rval
      can=8*(row+1)+col
   else: #black
      if row==0:
         return rval
      can=8*(row-1)+col
  
   if (col>0) and (col<8): #left capturing
      if ((board[can-1])/10)==oppo:
         rval.append(can-1)
   if (col>-1) and (col<7): #right capturing 
      if ((board[can+1])/10)==oppo:
         rval.append(can+1)
   if (board[can]/10)!=player:
         rval.append(can)
   return rval
     
def rookMove(pos):
   row=pos/8
   col=pos%8
   rval=[]
   i=0
   while i<8:
      if(i!=row):
         rval.append(i*8+col)
      if(i!=col):
         rval.append(row*8+i)
      i=i+1
   rval.sort()
   return rval

def rookBreak(rval,board,pos):
   row=pos/8
   col=pos%8
   player=(board[pos])/10
   oppo=3-player
   sub=[[],[],[],[]]
   newrval=[]
   sub[0]=rval[0:row]
   sub[0].sort(reverse=True)
   sub[1]=rval[row:(row+col)]
   sub[1].sort(reverse=True)
   sub[2]=rval[(row+col):(row+7)]
   sub[3]=rval[(row+7):]
   for item in sub:
      i=0
      while i<len(item):
         if (board[item[i]])/10==player:
            item=item[:i]
            break
         elif (board[item[i]])/10==oppo:
            item=item[:i+1]
            break
         i=i+1
      newrval=newrval+item
   newrval.sort()
   return newrval

def bishopMove(pos):
   rval=[]
   row=pos/8
   col=pos%8
   for u in range(row-1,-1,-1):
      i=row-u
      ul=col-i
      ur=col+i
      if (ul>-1)and(ul<8):
         rval.append(u*8+ul)
      if (ur>-1)and(ur<8):
         rval.append(u*8+ur)
   for l in range(row+1,8,1):
      i=l-row
      ll=col-i
      lr=col+i
      if (ll>-1)and(ll<8):
         rval.append(l*8+ll)
      if (lr>-1)and(lr<8):
         rval.append(l*8+lr)
   rval=onBoard(rval)
   rval.sort()
   return rval

def bishopBreak(rval,board,pos):
   sub=[[],[],[],[]]#ul,ur,dl,dr
   row=pos/8
   col=pos%8
   player=(board[pos])/10
   oppo=3-player
   newrval=[]
   for item in rval:
      if (item/8)<row:
         if (item%8)<col:
            sub[0].append(item)
         else: 
            sub[1].append(item)
      else:
         if (item%8)<col:
            sub[2].append(item)
         else:
            sub[3].append(item)
   sub[0].sort(reverse=True)
   sub[1].sort(reverse=True) 
   for item in sub:
      i=0
      while i<len(item):
         if (board[item[i]])/10==player:
            item=item[:i]
            break
         elif (board[item[i]])/10==oppo:
            item=item[:i+1]
            break
         i=i+1
      newrval=newrval+item
   newrval.sort()
   return newrval

def kingMove(pos):
   edge=0
   rval=[pos-9,pos-8,pos-7,pos-1,pos+1,pos+7,pos+8,pos+9]
   if pos%8==0:#on left edge
      rval=[pos-7,pos-8,pos+1,pos+9,pos+8]
      edge=1
   elif pos%8==7:#on right edge
      rval=[pos-9,pos-8,pos-1,pos+7,pos+8]
      edge=1
   if edge==0:
      rval=[pos-9,pos-8,pos-7,pos-1,pos+1,pos+7,pos+8,pos+9]
   rval=onBoard(rval)
   return rval

def knightMove(pos):
   rval=[]
   row=pos/8
   col=pos%8
   if col<6 and col>1:
      rval=[pos-17,pos-15,pos-10,pos-6,pos+17,pos+15,pos+10,pos+6]
   else:
      if col==1: #left edge 1
         rval=[pos-17,pos-15,pos-6,pos+17,pos+15,pos+10]
      if col==0: #left edge 0
         rval=[pos-15,pos-6,pos+17,pos+10]
      if col==6: #right edge 1
         rval=[pos-17,pos-15,pos-10,pos+17,pos+15,pos+6]
      if col==7: #right edge 0
         rval=[pos-17,pos-10,pos+15,pos+6]
   rval=onBoard(rval)
   return rval

def moveP(board,ipos,rpos):
   temp=board[rpos]
   board[rpos]=board[ipos]
   board[ipos]=0
   return True

def IsPositionUnderThreat(board,position,player):
   oppo=(30-player)
   pos=position
   pL=[]
   flag=0
   row=pos/8 
   col=pos%8
   #check king& pawn:
   pL=isEmpty(kingMove(pos),board,player)
   for item in pL:
      if (board[item]==(oppo+5)):
         flag=1
         return True
   #check pawn
   cL=[col-1,col,col+1]
   for i in pL:
      if i<0 or i>7:
         pL.remove(i)
   if player==10:
      pL=[x+8*(row+1) for x in cL]
   else:
      pL=[x+8*(row-1) for x in cL]
   pL=onBoard(pL)
   for item in pL:
      if (board[item]==oppo):
         flag=1
         return True
   #check bishop:
   pL=bishopBreak(bishopMove(pos),board,pos)
   for item in pL:
      if (board[item]==(oppo+2)) or (board[item]==(oppo+4)):
         flag=1
         return True
   #check rook:
   pL=rookBreak(rookMove(pos),board,pos)
   for item in pL:
      if (board[item]==(oppo+3)) or (board[item]==(oppo+4)):
         flag=1
         return True
   #check Knight
   pL=isEmpty(knightMove(pos),board,player)
   for item in pL:
      if board[item]==(oppo+1):
         flag=1
         return True
   if (flag==0):
      return False

