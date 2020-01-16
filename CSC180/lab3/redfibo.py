def fibo(n):
	if n==0:
		return 1
	elif n==1:
		return 1
	else:
		return fibo(n-1)+fibo(n-2) 

def fiboL(n):
	fibol=[]
	for i in range(0,n+1):
		fibol=fibol+[fibo(i)]
	return fibol

def redfibo(n):
	Fibol=list(fiboL(n))
	def reducingMulti(a,b):
		return a*b
	redFibo=reduce(reducingMulti,Fibol)
	return redFibo
