#include<stdio.h>
#include<stdlib.h>
#define msize 10
//节点结构 
typedef struct linkqueue{
	int data;//数据元素
	struct linkqueue *pre;
	struct linkqueue *next; 
}node; 
node* l=NULL;
node* r=NULL;
void initqueue()
{
	l=(node*)malloc(sizeof(node));
	r=l;
	l->next=l->pre=NULL;
}
/*第一次入队时,中间节点固定放右边第一次入队的元素*/
//左入队
void insert_left(int k)
{
	node* s=(node*)malloc(sizeof(node));
	s->data=k;
	s->pre=l->pre;
	s->next=l;
	l->pre=s;
	l=s;	
 } 
 //左出队
void delete_left() 
{
	if(l==r)
	{
		printf("空\n");
		return;
	}
	node* s=l;
	l=l->next;
	l->pre=NULL;
	printf("%d出队\n",s->data);
	free(s);
	s=NULL;
 } 
 //右入队
void insert_right(int k)
{
	node* s=(node*)malloc(sizeof(node));
    r->data=k;
    s->next=r->next;
    r->next=s;
    s->pre=r;
    r=s;
    
		
 } 
  //右出队
void delete_right() 
{
	if(l==r)
	{
		printf("空\n");
		return;
	}
	node* s=r;
	r=r->pre;
	r->next=NULL;
	printf("%d出队\n",r->data);
	free(s);
	s=NULL;
	
 } 
int main()
{
  	initqueue();
  	insert_right(1);
  	insert_right(2);
  	insert_right(3);
  	delete_left();
  	return 0;
  
  	
} 

