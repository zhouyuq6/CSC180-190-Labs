#include <stdio.h>

int anlboard(int *T, int sizeT);

int main(void){
	int i=0;
	int t[9];
	int board=0;
	printf("Enter your board: \n");
	for (i=0;i<9;i++){
		scanf("%d",&t[i]);
	}
	board = anlboard(t,9);
	printf("The board is now in %d\n",board);
	return 0;
}

int anlboard(int *T, int sizeT){
	int i=0;
	int flag=0;
	
	if (sizeT!=9){
		return -1;
	}
	
	for (i=0;i<sizeT;i++){
		if ((T[i]!=0)&&(T[i]!=1)&&(T[i]!=2)){
			return -1;
		}
		else if(T[i]==0){
			flag = 1;
		}
	}
	
	if ((T[0]==T[1])&&(T[1]==T[2])&&(T[2]!=0)){
		return T[0];
	}
	else if ((T[3]==T[4])&&(T[4]==T[5])&&(T[5]!=0)){
		return T[3];
	}
	else if ((T[6]==T[7])&&(T[7]==T[8])&&(T[8]!=0)){
		return T[6];
	}
	else if ((T[0]==T[3])&&(T[3]==T[6])&&(T[6]!=0)){
		return T[0];
	}
	else if ((T[1]==T[4])&&(T[4]==T[7])&&(T[7]!=0)){
		return T[1];
	}
	else if ((T[2]==T[5])&&(T[5]==T[8])&&(T[8]!=0)){
		return T[2];
	}
	else if ((T[0]==T[4])&&(T[4]==T[8])&&(T[8]!=0)){
		return T[0];
	}
	else if ((T[2]==T[4])&&(T[4]==T[6])&&(T[6]!=0)){
		return T[2];
	}
	else if (flag==1){
		return 0;
	}
	else {
		return 3;
	}
	
}

