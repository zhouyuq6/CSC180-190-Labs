#include <stdio.h>
#include <stdlib.h>
#include "avlrot.h"

int main(void) {
   avlNode *root=NULL;
   int depth=0;
   printf("\nTree 1:A MajorRight MinorLeft Tree\n");
   add_bst(&root,3);
   add_bst(&root,1);
   add_bst(&root,18);
   add_bst(&root,11);
   add_bst(&root,19); 
   add_bst(&root,8);
   printf("Printing In-order\n");
   printTreeInOrder(root);
   printf("Printing Levelorder,(#) represent balance \n");/* -1 Left, 0 balanced, +1 Right */
   printLevelOrder(root);
   printf("\nIs this tree an AVL?(0-yes;-1-no): %d\n",isAVL(&root));

   printf("Now do MajR MinL rotation\n");
   dblrotate(&root,0);  
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL?(0-yes;-1-no): %d\n",isAVL(&root));
   
   root=NULL;
   printf("\nTree 2:A MajorLeft MinorRight Tree\n");
   add_bst(&root,16);
   add_bst(&root,10);
   add_bst(&root,18);
   add_bst(&root,8);
   add_bst(&root,12); 
   add_bst(&root,13);   
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL?(0-yes;-1-no): %d\n",isAVL(&root));

   printf("Now do MajL MinR rotation\n");
   dblrotate(&root,1);  
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL now?(0-yes;-1-no): %d\n",isAVL(&root));

   root=NULL;
   printf("\nTree 3:A Left Tree\n");
   add_bst(&root,16);
   add_bst(&root,10);
   add_bst(&root,18);
   add_bst(&root,8);
   add_bst(&root,12); 
   add_bst(&root,6);   
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL?(0-yes;-1-no): %d\n",isAVL(&root));

   printf("Now do Right rotation\n");
   rotate(&root,1);  
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL now?(0-yes;-1-no): %d\n",isAVL(&root));

   root=NULL;
   printf("\nTree 4:A Right Tree\n");
   add_bst(&root,16);
   add_bst(&root,15);
   add_bst(&root,18);
   add_bst(&root,17);
   add_bst(&root,20); 
   add_bst(&root,22);   
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL?(0-yes;-1-no): %d\n",isAVL(&root));

   printf("Now do Left rotation\n");
   rotate(&root,0);  
   printTreeInOrder(root);
   printLevelOrder(root);
   printf("\nIs this tree an AVL now?(0-yes;-1-no): %d\n",isAVL(&root));

   return 0;
}
