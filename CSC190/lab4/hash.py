def f(inval):
   rval=inval
   if (rval>100):
      rval=rval%100
   if (rval<10 and rval>=0):
      rval=rval+45
   if (rval<0):
      rval=-rval
   if (rval<=100 and rval>=10):
      return rval
   else:
      return f(rval)

