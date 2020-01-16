#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   llnode *add = NULL;
   int r=0;
   int a=0;
   int i=0;

   printf("List A\n");
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }
   r=ll_print(root);
   r=ll_free(root);

   printf("List B\n");
	root=NULL;
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_head(&root,i*100);
   }
   r=ll_print(root);
   /*printf("There is value 500: %d\n",ll_find_by_value(root,100));i*/
   printf("List C\n");
   r=ll_del_from_tail(&root);
   r=ll_del_from_head(&root);
   r=ll_add_to_tail(&root,800);
   r=ll_add_to_tail(&root,200);
   r=ll_print(root);
   printf("Find 1000: %d\n",ll_find_by_value(root,1000));
   printf("Find 500: %d\n",ll_find_by_value(root,500));
   printf("List D\n");
   r=ll_del_by_value(&root,200);
   r=ll_print(root);
   
   printf("List E\n");
   printf("a is: \n");
   for(i=1;i<6;i=i+1){
      a=ll_add_to_tail(&add,i*100);
   }
   a=ll_print(add);
   printf("root is: \n");
   r=ll_print(root);
   printf("The root+add is: \n");
   a=ll_concat(&root,&add);
   r=ll_print(root);

   printf("List F\n");
   r=ll_sort(&root);
   r=ll_print(root);
   printf("add\n");

   r=ll_free(root);
   free(add);
   return 0;
}
