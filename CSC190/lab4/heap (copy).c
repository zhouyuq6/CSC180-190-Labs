#include<stdio.h>
#include<stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap(HeapType *pHeap,int size){
   int i=0;
   if(size<=0){return -1;}
   pHeap->size=size;
   pHeap->end=0;
   pHeap->store=(int *)malloc(sizeof(int)*size);
   
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
