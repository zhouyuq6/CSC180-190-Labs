from bc import *

while True:
   try:
      x=raw_input()
   except EOFError:
      break
   print bc(x)
