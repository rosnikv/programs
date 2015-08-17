#include<stdio.h>
#include<malloc.h>

struct node{
	char data;
	struct node *link;
};
struct node *top1=NULL,*top2=NULL,*top3=NULL;

push(struct node **top,char item){
	struct node *new;
	new=malloc(sizeof(struct node));
	new->data=item;
	new->link=*top;	
	*top=new;
}

char pop(struct node **top){
	char item;
	struct node *new;
	if(*top==NULL)
		printf("Stack is empty\n");
	else{
		new=*top;
		item=new->data;
		*top=new->link;
		free(new);
		return(item);
	}

}

main(){
	int i=0,flag;
	char str[50];
	printf("Enter the word to check\t");
	scanf("%s",&str);

	while(str[i]!='\0'){
		push(&top1,str[i]);
		push(&top2,str[i++]);
	}

	while(top1!=NULL){
		push(&top3,pop(&top1));
	}

	while(top2!=NULL){
		if(pop(&top2)==pop(&top3))
			flag=1;
		else{
			flag=0;
			break;
		}
	}

	if(flag==1)
		printf("%s is a palindrome\n",str);
	else
		printf("%s is not a palindrome\n",str);
}
