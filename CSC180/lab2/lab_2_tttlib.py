from random import randint

def genBoard():
	return [0,0,0,0,0,0,0,0,0]

def convertBoardListToStingList(T):
    if len(T) != 9:
        return []
    accum=[]
    for i in range(0,len(T),1):
        if T[i]==0:
            accum = accum + [str(i)]
        elif T[i]==1:
            accum = accum + ['X']
        elif T[i]==2:
            accum = accum + ['O']
        else:
            return []
    return accum

def printBoard(T):
	A = convertBoardListToStingList(T)
	if A==[]:
		return False	
	else:
		print (' '+A[0]+' | '+A[1]+' | '+A[2]+' ')
		print ('---|---|---')
		print (' '+A[3]+' | '+A[4]+' | '+A[5]+' ')
		print ('---|---|---')
		print (' '+A[6]+' | '+A[7]+' | '+A[8]+' ')
		return True

def analyzeBoard(T):
	if len(T)!=9:
		return -1
	while len(T)==9:
		point = False
		for i in range(0,len(T)):
			if T[i]!= 0 and T[i]!=1 and T[i]!=2:
				return -1
				break
			if T[i] == 0:
				point = True
		
		if (T[0]==T[1]==T[2]==1 or T[3]==T[4]==T[5]==1 or T[6]==T[7]==T[8]==1 or T[0]==T[3]==T[6]==1 or T[1]==T[4]==T[7]==1 or T[2]==T[5]==T[8]==1 or T[0]==T[4]==T[8]==1 or T[2]==T[4]==T[6]==1):
			return 1
		elif (T[0]==T[1]==T[2]==2 or T[3]==T[4]==T[5]==2 or T[6]==T[7]==T[8]==2 or T[0]==T[3]==T[6]==2 or T[1]==T[4]==T[7]==2 or T[2]==T[5]==T[8]==2 or T[0]==T[4]==T[8]==2 or T[2]==T[4]==T[6]==2):
			return 2
		elif point:
			return 0
		else:
			return 3

def genRandomMove(T,player):
     while True:
         if (analyzeBoard(T)!=0) or (player!=1 and player!=2):
             return -1
             break
         while True:
             u = randint(0,8)
             if T[u] == 0:
                 return u
                 break

def genWinningMove(T,player):
	if (analyzeBoard(T)!=0) or (player!=1 and player!=2):
		return -1
	for i in range(0,len(T)):
		if T[i]==0:
			Tb=list(T)
			Tb[i]=player
			if analyzeBoard(Tb)==player:
				return i
	return -1

def genNonLoser(T,player):
	if player == 1:
		opponent = 2
	else:
   		opponent = 1
	return genWinningMove(T,opponent)


