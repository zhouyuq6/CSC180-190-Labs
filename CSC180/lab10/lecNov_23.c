#include<stdio.h>
#include<stdlib.h>

int stringPrint(char *a);

int main(void){
   char string[]="helloman";
   stringPrint(string);
   return 0;
}

int stringPrint(char *a){
   int i=0;
   while(1){
      if(a[i]=='\0'){
         break;
      }else{
          printf("%c",a[i]);
          i++;
      }
   }printf("\n");
   return 0;
}

int strlen(char *str){
   int rval=0;
   while(str[rval]!='\0'){
      rval++;
   }
   return rval;
}

char * strcat(char *str1, char *str2){
   int n1,n2,nd;
   int i=0;
   char *out;
   n1=strlen(str1);
   n2=strlen(str2);
   nd=n1+n2+nd;
   out=(char*)malloc(sizeof(char)*nd);
   while(str1[i]!='\0'){out[i]=str1[i];i++;}
   while(str2[i-n1]!='\0'){out[i]=str2[i-n1];i++;}


}

