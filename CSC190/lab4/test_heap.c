#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int main(void){
   HeapType *heapA;
   int *rval=NULL;
   int a[]={9,8,7,6,5,4,3,2,1,0};
   int size=0;
   int i=0;
   int key=0;

   initHeap(heapA,15);
   printf("The heap is of size 15\n The heap is:\n"); 
   for(i=0;i<10;i=i+1){
      addHeap(heapA,a[i]);
   }
   for(i=0;i<(heapA->end);i=i+1){
      printf("%d ",heapA->store[i]);
   }   
   printCheck(heapA,0); 

   printf("\nDifferent order\n");
   printf("In order: \n"); 
   inorder(heapA,&rval,&size);
   printf("size: %d\n",size); 
   for(i=0;i<size;i=i+1){
      printf("%d ",rval[i]);
   }
   
   rval=NULL;
   size=0;
   printf("\nPreorder: \n"); 
   preorder(heapA,&rval,&size);
   printf("size: %d\n",size); 
   for(i=0;i<size;i=i+1){
      printf("%d ",rval[i]);}

   rval=NULL;
   size=0;
   printf("\nPostorder: \n"); 
   postorder(heapA,&rval,&size);
   printf("size: %d\n",size); 
   for(i=0;i<size;i=i+1){
      printf("%d ",rval[i]);}

   printf("\n\nAdd more to the heap: \n");
   for(i=10;i<16;i=i+1){
      addHeap(heapA,i);
   }
   for(i=0;i<(heapA->end);i=i+1){
      printf("%d ",heapA->store[i]);
   } 
   
   printCheck(heapA,0); 
   

   for(i=-3;i<20;i=i+3){
      printf("Searching key=%d. result:%d\n",i,findHeap(heapA,i));
   }
   
   printf("\nRepeat deleting for 5 times");

   for(i=0;i<5;i=i+1){
      delHeap(heapA,&key);
      printf("\n#%d: Max key is %d",i,key);
      printCheck(heapA,0); 
   }

   return 0; 
}
