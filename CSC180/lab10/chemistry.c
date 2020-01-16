#include<stdio.h>
#include<stdlib.h>

struct formula;
struct atom;
struct bondNode;

struct formula{
   int atomNum;
   int count;
   struct formula *aNext;
};

struct atom{
   int atomicNumber;
   struct bondNode *bondList;
};

struct bondNode{
   int strength;
   struct atom *pAtom;
   struct bondNode *pNext;
};

typedef struct formula formula;
typedef struct atom atom;
typedef struct bond bondNode;

int getAtom(atom *pAtom,formula *pFm){
   int i;
   if (pAtom==NULL){
      return 0;
   else{ 
      add_value(pFm,pAtom->atomicNumber);
      getBonds(atom *pAtom,int *size);
   }

}

int getBonds()

int add_value(formula **pFm, int val){
   if(pFm==NULL){return -1;}
   if(*pFm==NULL){
      insert(pFm,val);

   }
   else if((pFm->atomNum)==val){
      (*pFm)->count=(*pFm)->count+1;
      return 0;
   }else{
      return add_value(&((*pFm)->pNext),val);
   }
}

int insert(formula **pFm, int val){
   if(pFm==NULL){
      return -1;
   }
   else if(*pFm==NULL){
      (*pFm)=(formula *)malloc(sizeof(formula));
      (*pFm)->atomNum=val;
      (*pFm)->count=1;
      (*pFm)->aNext=NULL;
      return 0;
   }else{
      return insert(&((*pFm)->pNext),val);
   }
}

int sort(formula *pform){
   int tempAtom;
   int tempCnt;
   if(pform==NULL){return -1;}
   if((*pform)->)

}

int genFormula(atom *pAtom,int **output,int *size){
   formula *fList=NULL;
   if(pAtom==NULL){return -1;}
   for
      pAtom

}


