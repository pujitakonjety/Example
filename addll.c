#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *start=NULL;
void display(struct node *start1)
{
	struct node *ptr=start1;
	printf("List is:");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void reverse(struct node *s)
{
	struct node *ptr,*temp1=NULL,*temp2=NULL;
	ptr=s;
	while(ptr!=NULL)
	{
		temp1=ptr;
		ptr=ptr->next;
		temp1->next=temp2;
		temp2=temp1;
	}
	s=temp2;
	display(s);
}

struct node* read()
{
	struct node *start=NULL,*nn;
	int i,n,x;
	printf("Enter number of nodes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("\n enter data");
		scanf("%d",&x);
		nn->data=x;
		nn->next=start;
		start=nn;
	}
	return start;
}
void add(struct node* s1,struct node *s2)
{
	struct node *p1=s1,*p2=s2,*nn,*p;
	int t=0;
	while(p1!=NULL&&p2!=NULL)
	{
		p1->data=p1->data+p2->data+t;
//	p1->next->data=p1->next->data+(p1->data/10);
		t=p1->data/10;
		p1->data=p1->data%10;
		p=p1;
		p1=p1->next;
		p2=p2->next;
	}
	if(t==1&&p2==NULL)
	{
		
		while(p1!=NULL)
		{
			p1->data=p1->data+t;
			t=p1->data/10;
			p1->data=p1->data%10;
			p=p1;
			p1=p1->next;
			
		}
		
	}
	if(t==1)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=1;
		p->next=nn;
		nn->next=NULL;
	}
	display(s1);
	reverse(s1);
}
int main()
{
	struct node *s1,*s2,*p1,*p2;
	s1=read();
	s2=read();
	add(s1,s2);
//	display(s1);
//	display(s2);
}
