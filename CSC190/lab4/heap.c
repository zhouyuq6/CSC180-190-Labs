#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int initHeap(HeapType *pHeap,int size){
   int i=0;
   if(size<=0){return -1;}
   pHeap->size=size;
   pHeap->end=0;
   pHeap->store=(int *)malloc(sizeof(int)*size);
   return 0;
}

int inorder(HeapType *pHeap,int **output,int *o_size){
   if(output==NULL){return -1;}
   if(*output==NULL){
     *output=(int *)malloc(sizeof(int)*(pHeap->end));
   }
   if(pHeap->store==NULL){return -1;}
   if (o_size==NULL){
   o_size=malloc(sizeof(int));}
   *o_size=0;
   printInorder(pHeap,0,output,o_size);
   return 0;  
}

int printInorder(HeapType *pHeap,int index,int **rval,int *cnt){
   int i=0;
   if (pHeap==NULL) {return -1;}   
   if ((index>=(pHeap->end))||(index<0)) {return -1;}   
   printInorder(pHeap,(index*2+1),rval,cnt);
   (*rval)[(*cnt)]=pHeap->store[index];
   *cnt=*cnt+1;
   printInorder(pHeap,(index*2+2),rval,cnt);
   return 0;
}

int preorder(HeapType *pHeap,int **output,int *o_size){
   if(output==NULL){return -1;}
   if(*output==NULL){
     *output=(int *)malloc(sizeof(int)*(pHeap->end));}
   if(pHeap->store==NULL){return -1;}
   if (o_size==NULL){
   o_size=malloc(sizeof(int));}
   *o_size=0;
   printPreorder(pHeap,0,output,o_size);
   return 0;
}

int printPreorder(HeapType *pHeap,int index,int **rval,int *cnt){
   int i=0;
   if (pHeap==NULL) {return -1;}   
   if ((index>=(pHeap->end))||(index<0)) {return -1;}

   (*rval)[(*cnt)]=pHeap->store[index];
   *cnt=*cnt+1;
   printPreorder(pHeap,(index*2+1),rval,cnt);
   printPreorder(pHeap,(index*2+2),rval,cnt);
}


int postorder(HeapType *pHeap,int **output,int *o_size){
   if(output==NULL){return -1;}
   if(*output==NULL){
     *output=(int *)malloc(sizeof(int)*(pHeap->end));}
   if(pHeap->store==NULL){return -1;}
   if (o_size==NULL){
   o_size=malloc(sizeof(int));}
   *o_size=0;
   printPostorder(pHeap,0,output,o_size);
   return 0;
}

int printPostorder(HeapType *pHeap,int index,int **rval,int *cnt){
   int i=0;
   if (pHeap==NULL) {return -1;}   
   if ((index>=(pHeap->end))||(index<0)) {return -1;}
   printPostorder(pHeap,(index*2+1),rval,cnt);
   printPostorder(pHeap,(index*2+2),rval,cnt);
   (*rval)[(*cnt)]=pHeap->store[index];
   *cnt=*cnt+1;
}

int delHeap(HeapType *pHeap, int *key){
   if (pHeap==NULL){return -1;}
   if (key==NULL) {return -1;}
   if ((pHeap->end)==0) {return -1;}
   *key=pHeap->store[0];
   pHeap->store[0]=pHeap->store[(pHeap->end)-1];
   pHeap->store[(pHeap->end)-1]=0;
   (pHeap->end)=(pHeap->end)-1;
   downSwap(pHeap,0);   
   return 0;
}

int downSwap(HeapType *pHeap,int index){
   int temp=0;  
   if ((index>=(pHeap->end))||(index<0)) {return -1;}

   if ((pHeap->store[index*2+1])>(pHeap->store[index*2+2])){
      if((pHeap->store[index])<(pHeap->store[index*2+1])){
         temp=pHeap->store[index];  
         pHeap->store[index]=pHeap->store[index*2+1];
         pHeap->store[index*2+1]=temp;
         downSwap(pHeap,(index*2+1));
      }
   }else{
      if((pHeap->store[index])<(pHeap->store[index*2+2])){
         temp=pHeap->store[index];  
         pHeap->store[index]=pHeap->store[index*2+2];
         pHeap->store[index*2+2]=temp;
         downSwap(pHeap,(index*2+2));
      }
   }

/*   
   if((pHeap->store[index])<(pHeap->store[index*2+1])){
      temp=pHeap->store[index];  
      pHeap->store[index]=pHeap->store[index*2+1];
      pHeap->store[index*2+1]=temp;
      downSwap(pHeap,(index*2+1));
   }
   if((pHeap->store[index])<(pHeap->store[index*2+2])){
      temp=pHeap->store[index];  
      pHeap->store[index]=pHeap->store[index*2+2];
      pHeap->store[index*2+2]=temp;
      downSwap(pHeap,(index*2+2));
   }
*/
   return 0;
}

int addHeap(HeapType *pHeap,int key){
   if ((pHeap->end)==(pHeap->size)) {return -1;}/*full heap*/  
   if (pHeap==NULL){
      return initHeap(pHeap,1);
   }
   (pHeap->end)=(pHeap->end)+1;
   pHeap->store[(pHeap->end)-1]=key;
   swap(pHeap,pHeap->end-1);
   return 0;
}

int swap(HeapType *pHeap,int index){
   int temp=0;
   if ((index>=(pHeap->end))||(index<0)) {return -1;}
   if((pHeap->store[index])>(pHeap->store[(index-1)/2])){
      temp=pHeap->store[index];  
      pHeap->store[index]=pHeap->store[(index-1)/2];
      pHeap->store[(index-1)/2]=temp;
      swap(pHeap,(index-1)/2);
   }
   return 0;
}

int findHeap(HeapType *pHeap,int key){
   int rval=0;
   int id=0;
   if(pHeap==NULL){return -1;}
   while(id<(pHeap->end)){
      if (pHeap->store[id]==key){
         rval=1;break;
      }
      id=id+1;
   }   
   return rval;
}

int printCheck(HeapType *pHeap,int level){
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
   for(i=5;i>level;i=i-1){printf("  ");}
   while(index<end){
      printf("%d",pHeap->store[index]);
      index=index+1;
      for(i=0;i<4-level;i=i+1){printf(" ");}
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

