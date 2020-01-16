from random import randint
class ttt:
	def __init__(self):
		self.T=[0,0,0,0,0,0,0,0,0]
	
	def convertBoardListToStingList(self):
	    if len(self.T) != 9:
	       	return []
		accum=[]
   		for i in range(0,len(self.T),1):
			if self.T[i]==0:
				accum = accum + [str(i)]
            		elif self.self.T[i]==1:
                		accum = accum + ['X']
            		elif self.self.T[i]==2:
                		accum = accum + ['O']
            		else:
                		return []
		return accum

	def printBoard(self):
		A = self.convertBoardListToStingList
		if A==[]:
			return False	
		else:
			print (' '+A[0]+' | '+A[1]+' | '+A[2]+' ')
			print ('---|---|---')
			print (' '+A[3]+' | '+A[4]+' | '+A[5]+' ')
			print ('---|---|---')
			print (' '+A[6]+' | '+A[7]+' | '+A[8]+' ')
			return True

	def analyzeBoard(self):
		if self.T[0] == self.T[1] == self.T[2] != 0:
			return self.T[0]
		if self.T[3] == self.T[4] == self.T[5] != 0:
			return self.T[3]
       		if self.T[6] == self.T[7] == self.T[8] != 0:
			return self.T[6]
        	if self.T[0] == self.T[3] == self.T[6] != 0:
			return self.T[0]
	        if self.T[1] == self.T[4] == self.T[7] != 0:
			return self.T[1]
        	if self.T[2] == self.T[5] == self.T[8] != 0:
			return self.T[2]
       		if self.T[0] == self.T[4] == self.T[8] != 0:
			return self.T[0]
	        if self.T[2] == self.T[4] == self.T[6] != 0:
			return self.T[2]

        	n_opens = 0
        	for i in range(0,len(self.T),1):
            		if self.T[i] == 0:
                		n_opens = n_opens + 1
        	if n_opens == 0:
            		return 3
        	else:
           		return 0

	def genRandomMove(self,player):
		n_opens = 0
		for i in range(0,len(self.T),1):
			if self.T[i] == 0:
				n_opens = n_opens + 1
		
		if n_opens == 0:
			return -1
		else:
			while True:	
				move=randint(0,8)
       				if self.T[move] == 0:
					return move

	def genWinningMove(self,player):
		move = -1
   		for i in range(0,len(self.T),1):
			if self.T[i]==0:
				test=ttt()
				test.copy(self)
				test.Move(i,player)
         			if test.analyzeBoard()==player:			
					move = i
					break
   		return move

	def genNonLoser(self,player):
		if player == 1:
			opponent = 2
		else:
			opponent = 1
		
		return self.genWinningMove(opponent)

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
			for i in range (0,len(self.T),1):
				self.T[i]=source.T[i]
			return True
#hello

