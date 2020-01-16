import random

class conway:
	def __init__(self,row,col,type):
		if row<=0 or col<=0:
			return False
		self.matrix=[[]]
		for x in range(row):
			for y in range(col):
				if type=='zeros':
					self.matrix[x].append(0)
				elif type=='random':
					self.matrix[x].append(random.choice([0,1]))
			self.matrix.append([])
		self.row=row
		self.col=col

	def getDisp(self):
		string=""
		for i in range(self.row):
			for j in range(self.col):
				if self.matrix[i][j]==0:
					string=string+" "
				else:
					string=string+"*"
			string = string+"\n"
		return string

	def printDisp(self):
		out=self.getDisp()
		print (out)
		return True

	def setPos(self,r,c,val):
		if (val!=0 and val!=1):
			return False
		elif r>self.row or c>self.col or r<0 or c<0:
			return False
		else:
			self.matrix[r][c]=val
			return True

	def getNeighbours(self,r,c):
		if r>self.row or c>self.col or r<0 or c<0:
			return False

		outPoint=[[r-1,c-1],[r-1,c],[r-1,c+1],[r,c-1],[r,c+1],[r+1,c-1],[r+1,c],[r+1,c+1]]
		outList=[]
		for i in range(0,8):
			if outPoint[i][0]==-1:
				outPoint[i][0]=self.row-1
			elif outPoint[i][0]==self.row:
				outPoint[i][0]=0
			if outPoint[i][1]==-1:
				outPoint[i][1]=self.col-1
			elif outPoint[i][1]==self.col: 
				outPoint[i][1]=0
			outList.append(self.matrix[outPoint[i][0]][outPoint[i][1]])
		return outList

	def evolve(self,rule):
		next=conway(self.row,self.col,'zeros')
		for r in range(0,self.row):
			for c in range(0,self.col):
				next.setPos(r,c,rule(self.matrix[r][c],self.getNeighbours(r,c)))
		self.matrix=next.matrix
		return True
