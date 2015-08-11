#include<stdio.h>
#include<malloc.h>

struct node{
	char data;
	struct node *link;
};

struct node *top,*front,*rear;
//*top=NULL,*front=NULL,*rear=NULL;

push(struct node **s,char item){
	struct node *new;
	new=malloc(sizeof(struct node));
	new->data=item;
	new->link=*s;
	*s=new;
}

char pop(struct node **s){
	char item;
	struct node *new;
	if(*s==NULL)
		printf("Stack is empty\n");
	else{
		new=*s;
		item=new->data;
		*s=new->link;
		free(new);
		return(item);
	}
}

enqueue(struct node **f,struct node **r,char item){
	struct node *new;
	new=malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;

	if(*f==NULL)
		*f=new;
	else
		(*r)->link=new;
	*r=new;
}

char dequeue(struct node **f,struct node **r){
	struct node *new;
	char item;

	if(*f==NULL)
		printf("Queue is empty\n");
	else{
		new=*f;
		item=new->data;
		*f=new->link;
		free(new);
		if(*f==NULL)
			*r=NULL;//Queue empty on deletion		
	}
	return item;
}

main(){
	int i=0,flag;
	char str[50];
	printf("Enter the word\n");
	scanf("%s",&str);

	while(str[i]!='\0'){
		push(&top,str[i]);
		enqueue(&front,&rear,str[i++]);
	}

	while(top!=NULL){
		if(pop(&top)==dequeue(&front,&rear))
			flag=1;
		else{
			flag=0;
			break;
		}
	}

	if(flag==1)
		printf("%s is palindrome\n",str);
	else
		printf("%s is not palindrome\n",str);

}
