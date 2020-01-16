import redfibo_ref
import redfibo

tot = 0
score = 0

for i in range(0,20):
   tot += 5
   dut=redfibo.fibo(i)
   ref=redfibo_ref.fibo(i)
   if dut != ref:
      print "ERR: fibo(",i,") expected:",ref,"got:",dut
   else:
      score += 5

   tot += 5
   dut=redfibo.fiboL(i)
   ref=redfibo_ref.fiboL(i)
   if dut != ref:
      print "ERR: fiboL(",i,") expected:",ref,"got:",dut
   else:
      score += 5

   tot += 10 
   dut=redfibo.redfibo(i)
   ref=redfibo_ref.redfibo(i)
   if dut != ref:
      print "ERR: redfibo(",i,") expected:",ref,"got:",dut
   else:
      score += 10




print "SCORE: ",float(score)/float(tot)*100,"[",score,tot,"]"
