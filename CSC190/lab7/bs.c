#include <stdio.h>
#include <stdlib.h>

int bs(int *x,int size,int (*compare)(int x,int y)){
   int i=0;
   int swapped=0;
   int temp=0;
   while(swapped==0){
      swapped=-1;
      for (i=0;i<size-1;i=i+1){
         if ((*compare)(x[i],x[i+1])==-1){
            temp=x[i];
            x[i]=x[i+1];
            x[i+1]=temp;
            swapped=0;
         }
      }
   }
   return 0;  
}

int lt(int x, int y){
   if (x>=y){
      return 0;
   }
   else{
      return -1;
   }
}

int gt(int x, int y){
   if (x<=y){
      return 0;
   }
   else{
      return -1;
   }
}

