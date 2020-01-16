#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_head(llnode **x,char value);
int llnode_add_to_tail(llnode **x,char value);
int llnode_print_from_head(llnode *x);
int llnode_print_from_tail(llnode *x);
int push(llnode **x, char value);
int pop(llnode **x, char* return_value);

int llnode_add_to_head(llnode **x,char value){
   llnode *old_head;
   if(x==NULL) { return -1;}
   old_head=*x;
   *x=(llnode *)malloc(sizeof(llnode));
   (*x)->value=value;
   (*x)->next=old_head;
   return 0;
}

int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
	 return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
	 return 0;
      }
   }
}

int push(llnode **x, char value){
   if (x==NULL){return -1;}
   else{
   return llnode_add_to_head(x,value);
   }
}

int pop(llnode **x, char* return_value){
   llnode* temp=NULL;
   if (x==NULL) {return -1;}
   else if (*x==NULL){return -1;}
   if (((*x)->value == '\n')||((*x)->value == ' ')){
      temp=(*x)->next;
      free(*x);
      *x=temp;
   }
   *return_value=(*x)->value;
   temp=(*x)->next;
   free(*x);
   *x=temp;
   return 0;
}

int main(void) {
   int n=0;
   int flag=0; 
   char value='0';
   int rvalue=0;
   llnode *input_list=NULL;
   llnode *stack=NULL;
   char popval='a';

   while(scanf("%c",&value) != EOF){
      push(&input_list,value);
      if((value=='(')||(value=='[')||(value=='{')){
         push(&stack,value);
      }
      else if(value==')'){
         pop(&stack,&popval);
	 if(popval!='('){
	    flag=-1;break;
	 }
      }
      else if(value==']'){
         pop(&stack,&popval);
	 if(popval!='['){
	    flag=-1;break;
	 }
      }
      else if(value=='}'){
         pop(&stack,&popval);
	 if(popval!='{'){
	    flag=-1;break;
	 }
      }
      n=n+1;
   }
   
   if (flag==-1){
      printf("FAIL,%d\n",n);
   }else{
      printf("PASS\n");
   }
   return 0;
}
