class ttt:
	from random import randint
	def __init__(self):
		self.T=[0 for i in range(0,9)]
	
	def convertBoardListToStingList(self):
	    if len(self.T) != 9:
	       	return []

		accum=[]
   		for i in range(0,len(self.T),1):
			if self.T[i]==0:
				accum = accum + [str(i)]
            elif self.T[i]==1:
                accum = accum + ['X']
            elif self.T[i]==2:
                accum = accum + ['O']
            else:
                return []
		return accum

	def printBoard(self):
		A = convertBoardListToStingList(self.T)
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
		if len(self.T)!=9:
			return -1
		while len(self.T)==9:
			point = False
			for i in range(0,len(self.T)):
				if self.T[i]!= 0 and self.T[i]!=1 and self.T[i]!=2:
					return -1
					break
				if self.T[i] == 0:
					point = True
		
			if (self.T[0]==self.T[1]==self.T[2]==1 or self.T[3]==self.T[4]==self.T[5]==1 or self.T[6]==self.T[7]==self.T[8]==1 or self.T[0]==self.T[3]==self.T[6]==1 or self.T[1]==self.T[4]==self.T[7]==1 or self.T[2]==self.T[5]==self.T[8]==1 or self.T[0]==self.T[4]==self.T[8]==1 or self.T[2]==self.T[4]==self.T[6]==1):
				return 1
			elif (self.T[0]==self.T[1]==self.T[2]==2 or self.T[3]==self.T[4]==self.T[5]==2 or self.T[6]==self.T[7]==self.T[8]==2 or self.T[0]==self.T[3]==self.T[6]==2 or self.T[1]==self.T[4]==self.T[7]==2 or self.T[2]==self.T[5]==self.T[8]==2 or self.T[0]==self.T[4]==self.T[8]==2 or self.T[2]==self.T[4]==self.T[6]==2):
				return 2
			elif point:
				return 0
			else:
				return 3

	def genRandomMove(self,player):
	     while True:
	         if (analyzeBoard(self.T)!=0) or (player!=1 and player!=2):
	             return -1
	             break
	         while True:
	             u = randint(0,8)
	             if self.T[u] == 0:
	                 return u
	                 break

	def genWinningMove(self,player):
		if (analyzeBoard(self.T)!=0) or (player!=1 and player!=2):
			return -1
		Tb=list(self.T)		
		for i in range(0,len(Tb),1):
			if self.T[i]==0:
				Tb[i]=player
				if analyzeBoard(Tb)==player:
					return i
				Tb[i]=0
		return -1

	def genNonLoser(self,player):
		if player == 1:
			opponent = 2
		else:
			opponent = 1
		
		return genWinningMove(self.T,opponent)

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


