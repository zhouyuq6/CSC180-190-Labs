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

int hs(int *x,int size,int (*compare)(int x,int y)) {
   intHeap_T heap;
   int i=0;
   heap.store=(int *)malloc((size+1)*sizeof(int));
   heap.size=size+1;
   heap.end=0; /* empty heap condition; obey this spec */
   heap.compare = compare;
   for(i=0;i<size;i=i+1){
      store(&heap,x[i]);
   }
   for(i=0;i<size;i=i+1){
      retrieve(&heap,&x[i]);
   }
   return 0;
}

