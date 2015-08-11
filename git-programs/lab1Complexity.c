//PROGRAM DONE BY ROSNI KV 
//MTECH AI  15MCMI15 - IT LAB - ASSIGNMENT 1

#include<stdio.h>
#include<time.h>
#define MAX 4000000000u
#define MAX2 100000
#define MAX4 500
#define MAXE 50

int orderNlogN(long unsigned int N){

	clock_t t1,t2;
	long unsigned int count=0;
	long unsigned int i,j;

	t1=clock();

	for(i=0;i<N;i++)
		for(j=1;j<N;j*=2)
			count=count+1;
	t2=clock();

printf("%lu\t\t\t%f\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);
}

long int order2N(int N){
	
	if(N==0)
		return 1;

	else if(N==1)
		return 1;
	else
		return order2N(N-1)+order2N(N-2);

}


int orderN4(long unsigned int N){
	clock_t t1,t2;
	long unsigned int count=0;
	long unsigned int i,j,k,l;

	t1=clock();
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			for(k=0;k<N;k++)
				for(l=0;l<N;l++)
					count=count+1;

	t2=clock();

	printf("%lu\t\t\t%f\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);

}

int orderN(long unsigned int N){
	clock_t t1,t2;
	long unsigned int sum=0;
	long unsigned int i;

	t1=clock();
 	for(i=0;i<N;i++){
		sum=sum+i;
	}
	t2=clock();

printf("%lu\t\t\t%f\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);

}

orderN2(long unsigned int N){
	long unsigned int count=0,i,j;
	clock_t t1,t2;
	t1=clock();
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			count++;

	t2=clock();

	printf("%lu\t\t\t%f\n",N,(double)(t2-t1)/CLOCKS_PER_SEC);

}


int main(){
long unsigned int i;
long int value;

//Checking order of N algorithm
printf("\nValue of N\t\tTime taken by order N\n");
	for(i=1;i<=MAX;i+=400000000u)
		orderN(i);

//checking order of N^2 algorithm
printf("\nValue of N\t\tTime taken by order N^2\n");
	for(i=1;i<=MAX2;i+=40000u)
		orderN2(i);

//checking for order of N^4 algorithm
printf("\nValue of N\t\tTime taken by order N^4\n");
	for(i=0;i<=MAX4;i+=250)
		orderN4(i);

//checking for order of 2^N algorithm
clock_t t1,t2;
printf("\nValue of N\t\tTime taken by order 2^N\n");
	for(i=0;i<=MAXE;i+=25){
		t1=clock();	
		value=order2N(i);
		t2=clock();
		printf("%lu\t\t\t%f\n",i,(double)(t2-t1)/CLOCKS_PER_SEC);
	}

//checking for order of NLOGN algorithm
printf("\nValue of N\t\tTime taken by order NlogN\n");
	for(i=0;i<=MAX2;i+=40000u)
		orderNlogN(i);

}	

