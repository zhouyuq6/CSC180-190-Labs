class counter:
	def __init__(self,initCnt):
		self.cnt = initCnt

	def evolve(self,x):
		tmp = self.cnt
		self.cnt = tmp + x

	def getState(self):
		return self.cnt

#EQ1: self.cnt(state at time n+1) = self.cnt(state at time n) + x
