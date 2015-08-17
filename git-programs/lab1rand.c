//PROGRAM DONE BY ROSNI K V 15MCMI15
//MTECH AL ITLAB ASSIGNMENT 1(OS)`:W
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static unsigned long next=1;

unsigned int random_(int RAND_MX){

	next=next*1103515245+12345;
	return((unsigned)(next/65536)%RAND_MX);
}

mysrand(unsigned int rnum){

	next = rnum;
}

int main(){

	int RAND_MX,Num,i;
	unsigned int rnum,r;
	time_t t;
	printf("Specify the range of random numbers [0-RAND_MX]\t");
	scanf("%d",&RAND_MX);

	printf("Enter number of random numbers to be generated\n");
	scanf("%d",&Num);

	for(i=0;i<Num;i++){
		rnum=random_(RAND_MX);
		mysrand(rnum);
		srand(time(&t));
		r=(rnum+rand())%RAND_MX;
		printf("%lu\n",r);
	}
	
//printf("%d\t%d\nRAND_MX,Num);

}
