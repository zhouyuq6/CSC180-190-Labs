#include<stdio.h>
#include<stdlib.h>

unsigned char FSR(unsigned char x){
   unsigned char oldbit0 = x & 0x1;
   unsigned char r = x >> 1;
   unsigned char newbit7 = oldbit0 << 7;
   r = r|newbit7;
   return r;
}

unsigned char prng(unsigned char x, unsigned char pattern){
   char oldbit0 = x & 0x01;
   unsigned char r = x >> 1;
   char newbit7 = oldbit0 << 7;
   r = r|newbit7;
   r = r ^ pattern;
   return r;
}

int crypt(char *data,unsigned int size,unsigned char password){
   unsigned char prngVal=0;
   unsigned char oldchar=0;
   int i=0;
   if (size<=0){return -1;}
   if (password==0){return -1;}
   prngVal=password;
   for (i=0;i<size;i=i+1){
      prngVal=prng(prngVal,0xb8);
      oldchar=(unsigned char)data[i];
      data[i]=(unsigned char)((oldchar)^(prngVal));
   }
   return 0;
}

int printHelp(char *a,int size){
   int i=0;
   for (i=0;i<size;i=i+1){
      printf("%x ",(unsigned char)a[i]);
   }
   printf("\n");
   return 0;
}

int main(void){
   unsigned char pw=0xb1;
   char *data=NULL;
   int i=0;
   data=(char*)malloc(5*sizeof(char));
   data[0]='h';
   data[1]='e';
   data[2]='l';
   data[3]='l';
   data[4]='o';
   printHelp(data,5);
   crypt(data,5,pw); 
   printf("testcrypt\n");
   printHelp(data,5);
   free(data);
   return 0;
}
