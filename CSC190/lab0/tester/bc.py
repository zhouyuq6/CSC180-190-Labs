def bc(str):
   outlist=[True,0]
   value=''
   flag=1
   stack=[]
   for i in range(0,len(str)):
      if((str[i]=='(')or(str[i]=='[')or(str[i]=='{')):
         stack=[str[i]]+stack
      elif((str[i]==')') or (str[i]==']') or (str[i]=='}')):
         if len(stack)!=0:
            value=stack.pop(0)

         if((str[i]==')') and (value!='(')):
            flag=0
            break
         elif((str[i]==']') and (value!='[')):
            flag=0
            break
         elif((str[i]=='}') and (value!='{')):
            flag=0
            break

   if flag==1:
      if len(stack)==0:
         outlist[0]=True
      else:
         outlist[0]=False
         outlist[1]=i
   else:
      outlist[0]=False
      outlist[1]=i
   return outlist
