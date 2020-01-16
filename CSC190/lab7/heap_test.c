#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int *store;
   unsigned int size;
   unsigned int end;
   int (*compare)(int x,int y);
}intHeap_T;

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

int retrieve(intHeap_T* heap,int *rvalue) {
   if (heap==NULL){return -1;}
   if (rvalue==NULL) {return -1;}
   if ((heap->end)==0) {return -1;}
   *rvalue=heap->store[0];
   heap->store[0]=heap->store[(heap->end)-1];
   heap->store[(heap->end)-1]=0;
   downSwap(heap,0);   
   (heap->end)=(heap->end)-1;
   return 0;
}

int downSwap(intHeap_T* pHeap,int index){
   int temp=0;  
   int childindex=0;
   if ((index>=(pHeap->end))||(index<0)) {return -1;}

   if ((index*2+1)>=(pHeap->end-1)){return 0;}
   else if((index*2+2)>=(pHeap->end-1)){childindex=index*2+1;}
   else{
      if (pHeap->compare(pHeap->store[index*2+1],pHeap->store[index*2+2])==0){
         childindex=index*2+1;
      }else {
         childindex=index*2+2;
      }
   }
   if(pHeap->compare(pHeap->store[childindex],pHeap->store[index])==0){
         temp=pHeap->store[index];  
         pHeap->store[index]=pHeap->store[childindex];
         pHeap->store[childindex]=temp;
         downSwap(pHeap,childindex);
   }
   return 0;
}

int store(intHeap_T* heap, int value){
   if(heap==NULL){return -1;}/*no heap*/
   if(heap->end==heap->size){return -1;}/*full heap*/
   heap->store[heap->end]=value;
   heap->end=heap->end+1;
   swap(heap,heap->end-1);
   return 0;
}

int swap(intHeap_T* pHeap,int index){
   int temp=0;
   if ((index>=(pHeap->end))||(index<0)) {return -1;}
   if(pHeap->compare(pHeap->store[(index-1)/2],pHeap->store[index])!=0){
      temp=pHeap->store[index];  
      pHeap->store[index]=pHeap->store[(index-1)/2];
      pHeap->store[(index-1)/2]=temp;
      swap(pHeap,(index-1)/2);
   }
   return 0;
}

int printCheck(intHeap_T* pHeap,int level){
   int i=0;
   int index=0;
   int end=0;
   index=expHelp(level)-1;
   end=expHelp(level+1)-1;
   if(index>(pHeap->end)){printf("\n");return 0;}
   if(end>(pHeap->end)){
      end=(pHeap->end);
   }
   printf("\n");
   for(i=6;i>level;i=i-1){printf("   ");}
   while(index<end){
      printf("%d",pHeap->store[index]);
      index=index+1;
      for(i=0;i<5-level;i=i+1){printf(" ");}
   }
   printCheck(pHeap,level+1);
   return 0;
}

int expHelp(int x){
   if(x==0){return 1;
   }else{
      return 2*expHelp(x-1);
   }
}

int main(void){
   intHeap_T heap;
   int i=0;
   int r=0;
   int rval=0;
   heap.store=(int *)malloc(1000*sizeof(int));
   heap.size=1000;
   heap.end=0; /* empty heap condition; obey this spec */
   heap.compare = gt;
   for(i=0;i<15;i=i+1){
      r=store(&heap,15-i);
      printCheck(&heap,0);
   }
   printf("start retrieve\n");
   for(i=0;i<15;i=i+1){
      r=retrieve(&heap,&rval);
      printf("%dth retrieve: %d\n",i,rval);
   }
   return 0;
}
