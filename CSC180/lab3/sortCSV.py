import sys

FIN=""
FOUT=""
COL=0
DIR=""
nargs=len(sys.argv)
skip=False
for i in range(1,nargs):
    if not skip:
        arg=sys.argv[i]
        print "INFO: processing",arg
        if arg == "--fin":
            if i != nargs-1:
                FIN=sys.argv[i+1]
                skip=True
        elif arg == "--fout":
            if i != nargs-1:
                FOUT=sys.argv[i+1]
                skip=True
        elif arg == "--col":
            if i != nargs-1:
                COL=int(sys.argv[i+1])
                skip=True
        elif arg == "--dir":
            if i != nargs-1:
                DIR=sys.argv[i+1]
                skip=True
        else:
            print "ERR: unknown arg:",arg
    else:
        skip=False

print "INFO: FIN",FIN
print "INFO: FOUT",FOUT
print "INFO: COL",COL
print "INFO: DIR",DIR

CSVFIN=str(FIN)
try:
		f=open(CSVFIN,'r')
		lines=f.readlines()
		f.close()

except:
   print "ERR: file",CSVFIN,"is not present or can't be opened"


accum=[]
for i in lines:
		j=i.split('\n')[0]
		k=j.split(',')
		r=[]
		for x in k:
				r = r + [float(x)]
		accum = accum + [r]

def dirToup(DIR):
	try:
		if DIR=='+':
			return True
		elif DIR=='-':
			return False
	except:
		print "ERR: Direction is invalid"
		

def genSortKey(col,up):
	if col>=len(accum[0]):
		print "ERR: Column number is invalid"	
	else:
		def key(x):
			return x[col] if up else -x[col]
		return key

up=dirToup(DIR)
sortKey=genSortKey(COL,up)
accum=sorted(accum,key=sortKey)

Z=''
for i in range(0,len(accum)):
	for j in range(0,len(accum[i])):
		Z = Z + str(accum[i][j])
		if j!=(len(accum[i])-1):
			Z = Z + ','
	Z = Z + '\n'

CSVFOUT=str(FOUT)
try:
		g=open(CSVFOUT,'w')
		g.write(Z)
		g.close()	
except:
   print "ERR: file",CSVFOUT,"is not present or can't be written"



