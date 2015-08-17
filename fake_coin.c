//Program done by ROSNI K V [15MCMI15]
//FAKE COIN PROBLEM USING DIVIDE AND CONQUER METHOD

#include<stdio.h>
#include<math.h>
#define MAX 20

int weight(int *coin,int low,int high){
	int i,sum=0;
	for(i=low;i<high;i++)
		sum=sum+*(coin+i);
return sum;
}

int fake_coin(int *coin,int low,int high){
	int part1,part2,part3;
	int weight1,weight2;
	if(low==high-1)
		return low;
	else{
		part1=ceil((double)(high-low)/3);
		part2=ceil((double)(high-low)/3);
		part3=(high-low)-2*ceil((double)(high-low)/3);

		weight1=weight(&(*coin),low,low+part1);
		weight2=weight(&(*coin),low+part1,low+part1+part2);

		if(weight1==weight2)
			fake_coin(&(*coin),low+2*part1,high);
		else if(weight1<weight2)
			fake_coin(&(*coin),low,low+part1);
		else
			fake_coin(&(*coin),low+part1,low+part1+part2);
	}
}		

main(){
	int n,coins[MAX];
	int i,found;

	printf("Enter number of coins\n");
	scanf("%d",&n);

	printf("Enter the coin weights(diff value<less> for fake coin only)\n");
	for(i=0;i<n;i++)
		scanf("%d",&coins[i]);

	found=fake_coin(coins,0,n);
	
	printf("Fake coin found at %d postion\n",found+1);

return 0;
}
	
