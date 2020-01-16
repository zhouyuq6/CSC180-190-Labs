def fibon(x):
	if x==0:
		return 1
	elif x==1:
		return 1
	else:
		return fibon(x-1)+fibon(x-2) 

for i in range(0,10):
	print fibon(i)

