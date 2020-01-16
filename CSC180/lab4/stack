class stack:
	def __init__(self):
		self.store=[]
	
	def push(self,x):
		self.store=self.store+[x]
		return True

	def pop(self):
		try:
			rval = self.store[len(self.store)-1]
			self.store=self.store[0:len(self.store)-1]
			return rval
		except:
			print "ERR: Stack is empty"
			return False

	def disp(self):
		top = len(self.store)-1
		for i in range(top,-1,-1):
			print self.store[i],"<<---top " if i==top else ""
		return True

