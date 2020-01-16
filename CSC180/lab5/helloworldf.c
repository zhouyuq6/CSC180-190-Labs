#include <stdio.h>

float bsqrt(float x, float y);
float myAbs(float x);

int main(void){
	int i;
	for (i=0;i<10;i++){
		float sqrt;
		sqrt = bsqrt((float)i,0.001);
		printf("The sqrt of %d is %f\n", i,sqrt);
	}
	
	return 0;
}

float bsqrt(float x, float y){
	float a,b;
	a = x/2;
	b = x/a;
	while (myAbs(a-b)>=y){
		a = (a+b)/2;
		b = x/a;
	}
	return a;
}


float myAbs(float x){
	if (x<0) {
		return -x;
	}
	else{
		return x;
	}
}
