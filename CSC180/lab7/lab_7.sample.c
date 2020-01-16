#include<stdio.h>
#include<stdlib.h>

int ge_blah(int *matrix, int rows, int cols, int *matrix_out);
int print(int *matrix, int rows, int cols);

int print(int *matrix, int rows, int cols) {
   int r=0;
   int c=0;

   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         printf("%4d ",matrix[r*cols + c]);
      }
      printf("\n");
   }
   return 0;
}

int ge_blah(int *matrix, int rows, int cols, int *matrix_out) {
   /* Here is an example of a program that takes an input
      matrix and writes out an output matrix, matrix_out, that is
      some function of the input matrix.
      It is obviously a prototypical function for your ge_fw/bw
   */
   int r=0;
   int c=0;
   if (matrix==NULL) {
      return -1;
   }
   if (matrix_out==NULL) {
      return -1;
   }
   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         matrix_out[r*cols + c] = 10000+matrix[r*cols + c]*2;
      }
   }
   return 0;
}

int main(void) {
   int rows=0, cols=0;
   int *m=NULL, *n=NULL; /* init value for ptrs */
   int r=0,c=0;
   int idx=0;
   int rval=0;

   printf("How many rows? ");
   scanf("%d",&rows);
   printf("How many cols? ");
   scanf("%d",&cols);

   /* dynamically allocate matrices m and n
      Note: malloc returns NULL if it failed; i.e., if the computer
      was unable to allocate memory as requested */
   m = (int *)malloc(sizeof(int)*rows*cols);
   if (m==NULL) {
      printf("ERR: failed to allocate m; malloc failed\n");
      return -1;
   }
   n = (int *)malloc(sizeof(int)*rows*cols);
   if (n==NULL) {
      printf("ERR: failed to allocate n; malloc failed\n");
      return -1;
   }

   /* construct the matrix with some unimaginative but pretty data */
   idx=0;
   for(r=0;r<rows;r=r+1) {
      for(c=0;c<cols;c=c+1) {
         m[r*cols + c] = idx;
         idx=idx+1;
      }
   }
   /* first step in debugging: print
      second step in debugging: roll your own convenient print function */
   printf("INFO: the input matrix is:\n");
   rval = print(m,rows,cols);
   /* if a function produces a return val ALWAYS CHECK THE RETURN VAL
      Do Not Be Lazy ... */
   if (rval != 0) {
      printf("ERR: print returned a non-zero status\n");
      return -1;
   }

   /* now call the function that processes m and produces n */
   rval = ge_blah(m, rows, cols, n);
   if (rval != 0) {
      printf("ERR: ge_blah returned a non-zero status\n");
      return -1;
   }
   printf("INFO: the output matrix is:\n");
   rval = print(n,rows,cols);
   if (rval != 0) {
      printf("ERR: print returned a non-zero status\n");
      return -1;
   }

   return 0;
}
