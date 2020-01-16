import tttlib
import tttlib_ref

print "INFO: sample auto tester"
print "INFO: tester MUST complete to receive a score"

errcnt = 0
tot    = 0

print "INFO: testing genBoard"
tot    += 1
if tttlib.genBoard() != [0 for i in range(0,9) ]:
   print "ERR: -1 point"
   errcnt += 1

print "INFO: testing printBoard errors"
tot    += 2
for i in range(10,100):
   err = False
   if tttlib.printBoard([0 for i in range(0,i)]) != False:
      err = True
if err:
   print "ERR: unchecked length"
   errcnt += 2

print "INFO: testing printBoard rval"
for i in [\
   [ 1,0,1, 0,1,0, 1,0,1 ],\
   [ 0,1,0, 1,0,1, 0,1,0 ],\
   [ 2,0,2, 0,2,0, 2,0,2 ],\
   [ 0,2,0, 2,0,2, 0,2,0 ],\
   [ 1,2,1, 2,1,2, 1,2,1 ],\
   [ 2,1,2, 1,2,1, 2,1,2 ],\
   [ 2,1,2, 1,2,1, 2,1,2 ],\
   [ 1,2,1, 2,1,2, 1,2,1 ]]:
   tot += 3
   if tttlib.printBoard(i) != True:
      print "ERR: legitmate board couldn't be printed: got False",i
      errcnt += 3

print "INFO: testing analyzeBoard: win cases"
for t in [ \
   [ 1,1,1, 0,0,0, 0,0,0 ], \
   [ 0,0,0, 1,1,1, 0,0,0 ], \
   [ 0,0,0, 0,0,0, 1,1,1 ], \
   [ 1,0,0, 1,0,0, 1,0,0 ], \
   [ 0,1,0, 0,1,0, 0,1,0 ], \
   [ 0,0,1, 0,0,1, 0,0,1 ], \
   [ 1,0,0, 0,1,0, 0,0,1 ], \
   [ 0,0,1, 0,1,0, 1,0,0 ], \
   [ 2,2,2, 0,0,0, 0,0,0 ], \
   [ 0,0,0, 2,2,2, 0,0,0 ], \
   [ 0,0,0, 0,0,0, 2,2,2 ], \
   [ 2,0,0, 2,0,0, 2,0,0 ], \
   [ 0,2,0, 0,2,0, 0,2,0 ], \
   [ 0,0,2, 0,0,2, 0,0,2 ], \
   [ 2,0,0, 0,2,0, 0,0,2 ], \
   [ 0,0,2, 0,2,0, 2,0,0 ]]:
   err = False
   dut = tttlib.analyzeBoard(t)
   ref = tttlib_ref.analyzeBoard(t)
   tot +=1
   if dut != ref:
      errcnt += 1
      err = True
      print "ERR: analyzeBoard [win]",t,dut,ref

print "INFO: testing analyzeBoard: play cases"
for i in range(0,9):
   for p in [1,2]:
      T=[0 for k in range(0,9)]
      T[i]=p
      err = False
      tot += 1
      if tttlib.analyzeBoard(T) != 0:
         err=True
         errcnt += 1
         print "ERR: analyseBoard [play]",T

print "INFO: testing analyzeBoard: draw cases"
for t in [\
   [ 1,1,2, 2,2,1, 1,1,2 ], \
   [ 2,2,1, 1,1,2, 2,2,1 ], \
   [ 1,2,1, 2,1,2, 2,1,2 ], \
   [ 2,1,2, 1,2,1, 1,2,1 ] ]:
   err = False
   tot += 1
   if tttlib.analyzeBoard(t) != 3:
      err=True
      errcnt += 1
      print "ERR: analyzeBoard [ draw]",t

print "INFO: testing genWinningMove & genNonLoser"
for (t,gold) in [\
   ([0,1,1,0,0,0,0,0,0], 0),\
   ([1,0,1,0,0,0,0,0,0], 1),\
   ([1,1,0,0,0,0,0,0,0], 2),\
   ([0,0,0,0,1,1,0,0,0], 3),\
   ([0,0,0,1,0,1,0,0,0], 4),\
   ([0,0,0,1,1,0,0,0,0], 5),\
   ([0,0,0,0,0,0,0,1,1], 6),\
   ([0,0,0,0,0,0,1,0,1], 7),\
   ([0,0,0,0,0,0,1,1,0], 8),\
   ([1,0,0,0,1,0,0,0,0], 8),\
   ([1,0,0,0,0,0,0,0,1], 4),\
   ([0,0,0,0,1,0,0,0,1], 0),\
   ([0,0,1,0,1,0,0,0,0], 6),\
   ([0,0,0,0,1,0,1,0,0], 2),\
   ([0,0,1,0,0,0,1,0,0], 4,),\
   ([0,1,0,0,0,0,0,0,0], -1),\
   ([1,0,0,0,0,0,0,0,0], -1),\
   ([1,0,0,0,0,0,0,0,0], -1),\
   ([0,0,0,0,1,0,0,0,0], -1),\
   ([0,0,0,0,0,1,0,0,0], -1),\
   ([0,0,0,1,0,0,0,0,0], -1),\
   ([0,0,0,0,0,0,0,0,1], -1),\
   ([0,0,0,0,0,0,0,0,1], -1),\
   ([0,0,0,0,0,0,1,0,0], -1),\
   ([1,0,0,0,0,0,0,0,0], -1),\
   ([0,0,0,0,0,0,0,0,1], -1),\
   ([0,0,0,0,1,0,0,0,0], -1),\
   ([0,0,1,0,0,0,0,0,0], -1),\
   ([0,0,0,0,0,0,1,0,0], -1),\
   ([0,0,1,0,0,0,0,0,0], -1)\
   ]:
   for player in [1,2]:
      tot += 5
      T=map(lambda x:player if x==1 else 0,t)
      r=tttlib.genWinningMove(T,player)
      if r != gold:
         print "ERR: genWinningMove:",T,"player:",player,"you:",r,"gold:",gold
         errcnt += 5
      tot += 5
      opponent=1 if player==2 else 2
      T=map(lambda x:opponent if x==1 else 0,t)
      r=tttlib.genNonLoser(T,player)
      if r != gold:
         print "ERR: genNonLoser:",T,"player:",player,"you:",r,"gold:",gold
         errcnt += 5

print "INFO: testing genRandomMove"
for i in [\
   [0,0,0,0,0,0,0,0,0],\
   [1,0,0,0,1,0,1,0,0],\
   [0,1,0,0,0,0,0,0,0],\
   [0,1,1,0,1,1,0,0,0],\
   [0,1,1,1,0,0,1,0,0],\
   [0,1,0,1,1,0,0,0,0],\
   [0,0,1,0,1,1,0,0,0],\
   [0,0,1,1,0,1,1,0,0],\
   [0,0,0,1,1,0,1,1,0],\
   [0,0,0,0,1,1,0,1,1],\
   [2,0,0,0,2,0,2,0,0],\
   [0,2,0,0,0,0,0,0,0],\
   [0,2,2,0,2,2,0,0,0],\
   [0,2,2,2,0,0,2,0,0],\
   [0,2,0,2,2,0,0,0,0],\
   [0,0,2,0,2,2,0,0,0],\
   [0,0,2,2,0,2,2,0,0],\
   [0,0,0,2,2,0,2,2,0],\
   [0,0,0,0,2,2,0,0,2]]:
   u=tttlib.genRandomMove(i,1)
   tot += 3
   if type(u) != int or u == -1:
      print "ERR: genRandomMove returned an erroneous result",i,u
      errcnt += 3
   elif i[u] != 0:
      print "ERR: genRandomMove returned occupied location, or board was modified",i,u
      errcnt += 3

print "INFO: testing genRandomMove"
for i in [\
   [1,1,1,1,1,1,1,1,1],\
   [1,2,1,2,1,2,1,2,1],\
   [2,2,2,2,1,2,2,2,2]]:
   tot += 3
   u=tttlib.genRandomMove(i,2)
   if not(u == -1):
      print "ERR: genRandomMove didn't return -1 for full board",i,u
      errcnt += 3

#print "You scored:",errcnt,"out of maximum badness",tot
print "GRADE:",tot-errcnt,"out of",tot
