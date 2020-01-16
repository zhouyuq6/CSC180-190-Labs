#include <stdio.h>
#include <stdlib.h>

struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
};
typedef struct bstNode bstNode;

struct llnode {
   bstNode *val;
   struct llnode *next;
};
typedef struct llnode llnode;

bstNode *dequeue(llnode **queue);
int enqueue(llnode **queue, bstNode *el);
int add_bst(bstNode **root,int val);
int printTreeInOrder(bstNode *root);
int printLevelOrder(bstNode *root);

bstNode *dequeue(llnode **queue){
   llnode *head=NULL;
   bstNode *rval=NULL;
   if(queue==NULL){return rval;}
   if(*queue==NULL){return rval;}

   head=(*queue)->next;
   rval=(*queue)->val;
   free(*queue);
   *queue=head;
   return rval;
}

int enqueue(llnode **queue, bstNode *el){
   if(queue==NULL){return -1;}
   if(*queue == NULL){
      *queue=(llnode *)malloc(sizeof(llnode));
      (*queue)->val=el;
      (*queue)->next=NULL;
      return 0;
   }else{
      return enqueue(&((*queue)->next),el);
   }
}

int add_bst(bstNode **root,int val) {
   if (root == NULL) { return -1; }
   if (*root == NULL) {
      *root = (bstNode *)malloc(sizeof(bstNode));
      (*root)->val=val;
      (*root)->l=NULL;
      (*root)->r=NULL;
      return 0;
   } else {
      if (val<((*root)->val)){
         return add_bst(&((*root)->l),val);
      }else{
         return add_bst(&((*root)->r),val);
      }
   }
}

int printTreeInOrder(bstNode *root){
   if (root==NULL) {return 0;}
   else{
      printTreeInOrder((root)->l);
      printf("%d\n",(root)->val);
      printTreeInOrder((root)->r);
      return 0;
   }
}

int printLevelOrder(bstNode *root){
   llnode *queue=NULL;
   bstNode *y=NULL;
   int i=1;
   enqueue(&queue,root);
   while(i=1){
      y=dequeue(&queue);
      if(y==NULL){break;}
      else{
         printf("%d ",(y)->val);
         if((y)->l!=NULL){
            enqueue(&queue,(y)->l);
         }
         if((y)->r!=NULL){
            enqueue(&queue,(y)->r);
         }
      }
   }
   return 0;
}

int main(void) {
   bstNode *root=NULL;
   int value=0;
/*   add_bst(&root,5);
   add_bst(&root,3);
   add_bst(&root,1);
   add_bst(&root,4);
   add_bst(&root,7);
   add_bst(&root,6);
   add_bst(&root,8);
*/
   while(scanf("%d",&value) != EOF){
      add_bst(&root,value);
   }
   printTreeInOrder(root);
   return 0;
}
