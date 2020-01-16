#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap(HeapType *pHeap,int size);
int addHeap(HeapType *pHeap,int key);
int inorder(HeapType *pHeap,int **output,int *o_size);
int printInorder(HeapType *pHeap,int index,int **rval,int *cnt);
int preorder(HeapType *pHeap,int **output,int *o_size);
int printPreorder(HeapType *pHeap,int index,int **rval,int *cnt);
int postorder(HeapType *pHeap,int **output,int *o_size);
int printPostorder(HeapType *pHeap,int index,int **rval,int *cnt);
int delHeap(HeapType *pHeap, int *key);
int downSwap(HeapType *pHeap,int index);
int swap(HeapType *pHeap,int index);
int findHeap(HeapType *pHeap,int key);
int printCheck(HeapType *pHeap,int level);
int expHelp(int x);

