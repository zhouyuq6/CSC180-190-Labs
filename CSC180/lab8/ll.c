#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else {
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
      llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value(llnode *pList,int val){
    if (pList == NULL){
        return -1;
    }
    else if (pList->val==val){
        return 0;
    }
    else{
        return ll_find_by_value(pList->next,val);
    }
}

int ll_del_from_tail(llnode **ppList){
   if (ppList==NULL){
      return -1;
   }
   else if(*ppList==NULL){
      return -1;
   }
   else if (((*ppList)->next)->next==NULL){
      ll_free((*ppList)->next);
      (*ppList)->next=NULL;
      return 0;
   }
   else{
      return ll_del_from_tail(&((*ppList)->next));
   }
}

int ll_del_from_head(llnode **ppList){
    llnode *temp;
    if (ppList==NULL){
        return -1;
    }
    else if(*ppList==NULL){
    	return -1;
    }
    else{
        temp=(*ppList)->next;
        free(*ppList);
        *ppList= temp;
	return 0;  
    }
}

int ll_del_by_value(llnode **ppList, int val){
    if (ppList==NULL){
        return -1;
    }
    else if(*ppList==NULL){
    	return 0;
    }
    else if((*ppList)->val==val){
    	ll_del_from_head(ppList);
	return ll_del_by_value(ppList,val);
    }
    else{
    	return ll_del_by_value(&((*ppList)->next),val);
    }

}

int ll_insert_in_order(llnode **ppList,int val) {
   /* we are going to iterate through the linked list to find the
      insertion point; we will need to track the prior node so we
      can stitch in the new node properly
      -> thus we will create two pointers to track the nodes
         "curr" and "prev"
   */
   llnode *prev = NULL;
   llnode *curr = NULL;

   if (ppList == NULL) { return -1; }
   if (*ppList == NULL) {
      /* if we're dealing with an empty linked list, just call
         add to head */
      return ll_add_to_head(ppList,val);
   }
   /* otherwise: we iterate through the list until will find the
      insert location */
   /* first we handle the degenerate case of the first node */
   if ((*ppList) -> val > val) {
      return ll_add_to_head(ppList,val);
   } else {
      prev = *ppList;
      curr = (*ppList)->next;
      while(curr != NULL) {
         if (curr->val > val) {
            break;
         } else {
            prev = curr;
            curr = prev->next;
         }
      }
      prev->next = (llnode *) malloc(sizeof(llnode));
      prev->next->val  = val;
      prev->next->next = curr;
      return 0;
   }
}

int ll_concat(llnode **pSrcA,llnode **pSrcB){
    if ((pSrcA==NULL)||(pSrcB==NULL)){
    	return -1;
    }
    else if((*pSrcA)->next==NULL){
    	(*pSrcA)->next=*pSrcB;
    	return 0;
    }
    else{
    	return ll_concat(&((*pSrcA)->next),pSrcB);
    }
}

int ll_sort(llnode **ppList){
    int temp;
    int swapped=1;
    llnode *point;
    if (ppList==NULL){
    	return -1;
    }
    while(swapped == 1){
    	point=*ppList;
	swapped=0;
	while((point->next)!=NULL){
	    if ((point->val) > (point->next->val)){
		temp=point->val;
		point->val=point->next->val;
		point->next->val=temp;
		swapped=1;
	    }
	    point=point->next;
	}
    }
    return 0;    
}
