#include <stdio.h>

int swap (int *a, int*b);

int main(void){
	int y = 0;
	int a = 100;
	int b = 30000;
	printf("before: %d, %d\n",a,b);
	y = swap(&a,&b);
	printf("after: %d, %d\n y = %d\n",a,b,y);
	return 0;
}

int swap (int *a, int*b){
	*a = 0;
	*b = 0;
	return 1;
}

