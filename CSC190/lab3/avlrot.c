#include <stdio.h>
#include <stdlib.h>
#include "avlrot.h"

avlNode *deQueue(qNode **queue){
   qNode *head=NULL;
   avlNode *rval=NULL;
   if(queue==NULL){return rval;}
   if(*queue==NULL){return rval;}

   head=(*queue)->nxt;
   rval=(*queue)->pval;
   free(*queue);
   *queue=head;
   return rval;
}

int enQueue(qNode **queue, avlNode *el){
   if(queue==NULL){return -1;}
   if(*queue == NULL){
      *queue=(qNode *)malloc(sizeof(qNode));
      (*queue)->pval=el;
      (*queue)->nxt=NULL;
      return 0;
   }else{
      return enQueue(&((*queue)->nxt),el);
   }
}

int getDepth(avlNode *root){
   int tempdep=0;
   int a=0;
   int b=0;
   if(root==NULL){return -1;}
   else{
      a=getDepth(root->l);
      b=getDepth(root->r);
      if(a<b){tempdep=b+1;}
      else{tempdep=a+1;}
   }
   return tempdep;
}

int getBalance(avlNode *root){
   int balance=0;
   int hLeft=0;
   int hRight=0;
   int delta=0;
   
   if(root==NULL){return 0;}
   hLeft=getDepth((root)->l);
   hRight=getDepth((root)->r);
   delta=hRight-hLeft;
   return delta;
}

int printTreeInOrder(avlNode *root){
   if (root==NULL) {return 0;}
   else{
      printTreeInOrder((root)->l);
      printf("%d\n",(root)->val);
      printTreeInOrder((root)->r);
      return 0;
   }
}

int printLevelOrder(avlNode *root){
   qNode *queue=NULL;
   avlNode *y=NULL;
   int i=1;

   enQueue(&queue,root);
   while(i=1){
      y=deQueue(&queue);
      if(y==NULL){break;}
      else{
         (y)->balance=getBalance(y);
         printf("%d(%d) ",(y)->val,(y)->balance);
         if((y)->l!=NULL){
            enQueue(&queue,(y)->l);
         }
         if((y)->r!=NULL){
            enQueue(&queue,(y)->r);
         }
      }
   }
   return 0;
}

int add_bst(avlNode **root,int val){
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root = (avlNode *)malloc(sizeof(avlNode));
      (*root)->val=val;
      (*root)->balance=0;
      (*root)->l=NULL;
      (*root)->r=NULL;
      return 0;
   } else {
      if (val<((*root)->val)){
         add_bst(&((*root)->l),val);
      }else{
         add_bst(&((*root)->r),val);
      }
   }
   (*root)->balance=getBalance(*root);
   return 0;
}

int isAVL(avlNode **root){
   qNode *q=NULL;
   avlNode *z=NULL;
   int i=1;
   int delta=0;
   int balance=0;

   if(root==NULL){return -1;}
   enQueue(&q,(*root));
   while(i=1){
      z=deQueue(&q);
      if(z==NULL){break;}
      else{
         delta=getBalance(z);
         if((delta>1)||(delta<-1)){
            balance=-1;
         }
         if((z)->l!=NULL){
            enQueue(&q,(z)->l);
         }
         if((z)->r!=NULL){
            enQueue(&q,(z)->r);
         }
      }
   }
   return balance;
}

int rotate(avlNode **root,unsigned int Left0_Right1){
   avlNode *t1=NULL;
   avlNode *t2=NULL;
   if(root==NULL){return -1;}
   if(*root==NULL){return -1;}
   if(Left0_Right1==0){
      t1=(*root)->r;
      t2=t1->l;
      t1->l=(*root);
      (*root)->r=t2;
   }
   else if(Left0_Right1==1){
      t1=(*root)->l;
      t2=t1->r;
      t1->r=(*root);
      (*root)->l=t2;
   }else{
      return -1;
   }
   (*root)=t1;
   return 0;
}

int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1){
   avlNode *minNode=NULL;
   
   if(root==NULL){return -1;}
   if(*root==NULL){return -1;}
   if(MajLMinR0_MajRMinL1==0){
      minNode=((*root)->r); 
   }
   else if(MajLMinR0_MajRMinL1=1){
      minNode=((*root)->l);
   }
   
   rotate(&minNode,1-MajLMinR0_MajRMinL1);
   
   if(MajLMinR0_MajRMinL1==0){
      (*root)->r=minNode;} 
   else if(MajLMinR0_MajRMinL1==1){
      (*root)->l=minNode;}
  
   rotate(root,MajLMinR0_MajRMinL1);   
   return 0;
}

