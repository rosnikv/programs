#include<stdio.h>
#include<limits.h>
#include<math.h>

struct max_subarray{
	int index_low;
	int index_high;
	int max_sum;
}ms_cross,ms_l,ms_r,ms0,ms,ms_c,prev_ms;

//int max(int a,int b){return (a>b)?a:b;}

struct max_subarray max_crossing(int array[],int low,int mid,int high){
	int sum=0,i,left;
	int left_sum=INT_MIN;
		for(i=mid;i>=low;i--){
			sum=sum+array[i];
			if(sum>left_sum){
				left_sum=sum;
				left=i;
			}
		}
//printf("left ---> %d\n",left_sum);
	sum=0;
	int right_sum=INT_MIN,right;
	for(i=mid+1;i<=high;i++){
		sum=sum+array[i];
		if(sum>right_sum){
			right_sum=sum;
			right=i;
		}
	}
//printf("right--->%d\n",right_sum);
	ms_c.index_low=left;
	ms_c.index_high=right;
	ms_c.max_sum=left_sum+right_sum;
//printf("sum----->%d\n",ms_c.max_sum);
	return ms_c;
}	

struct max_subarray max_subarr(int array[],int low,int high){
	int mid;
	ms0.index_low=low;
	ms0.index_high=high;
	ms0.max_sum=array[low];

	if(low==high)
		return ms0;
	else{
		mid=floor((low+high)/2);
//printf("\n%d\n",mid);
		ms_l=max_subarr(array,low,mid);
printf("left ----->%d\n",ms_l.max_sum);
		ms_r=max_subarr(array,mid+1,high);
printf("right------->%d\n",ms_r.max_sum);
		ms_cross=max_crossing(array,low,mid,high);
printf("cross sum ---->%d\n",ms_cross.max_sum);
	if(((ms_l.max_sum)>=(ms_r.max_sum))&&((ms_l.max_sum)>=(ms_cross.max_sum))&&(ms_l.max_sum>=prev_ms.max_sum)){
		prev_ms=ms_l;
		return ms_l;
	}
	else if(((ms_r.max_sum)>=(ms_l.max_sum)) && ((ms_r.max_sum)>=(ms_cross.max_sum))&&(ms_r.max_sum>=prev_ms.max_sum)){
		prev_ms=ms_r;
		return ms_r;
	}
	else if(ms_cross.max_sum>=prev_ms.max_sum){
		prev_ms=ms_cross;
		return ms_cross;
	}
	}
	

}

main(){
	int array[50];
	int i,num;
	
	printf("Enter the number of elements\n");
	scanf("%d",&num);

	printf("Enter the elements\n");
	for(i=0;i<num;i++)
		scanf("%d",&array[i]);

	struct max_subarray ms;
	ms=max_subarr(array,0,num-1);

	printf("\nThe index values are %d and %d of the max_subarray with sub_array sum %d\n",(ms.index_low),(ms.index_high),(ms.max_sum));


}
