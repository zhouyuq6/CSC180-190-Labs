struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;

struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;

avlNode *deQueue(qNode **queue);
int enQueue(qNode **queue, avlNode *el);
int getDepth(avlNode *root);
int getBalance(avlNode *root);
int printTreeInOrder(avlNode *root);
int printLevelOrder(avlNode *root);
int add_bst(avlNode **root,int val);
int isAVL(avlNode **root);
int rotate(avlNode **root,unsigned int Left0_Right1);
int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1);
