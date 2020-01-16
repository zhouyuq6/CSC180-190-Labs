def rule(val,List):
	s=sum(List)
	if val==1:
		if s==2 or s==3:
			return 1
		else:
			return 0
	else:
		if s==3:
			return 1
 		else:
			return 0

