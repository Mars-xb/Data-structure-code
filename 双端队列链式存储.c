#include<stdio.h>
#include<stdlib.h>
#define msize 10
//�ڵ�ṹ 
typedef struct linkqueue{
	int data;//����Ԫ��
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
/*��һ�����ʱ,�м�ڵ�̶����ұߵ�һ����ӵ�Ԫ��*/
//�����
void insert_left(int k)
{
	node* s=(node*)malloc(sizeof(node));
	s->data=k;
	s->pre=l->pre;
	s->next=l;
	l->pre=s;
	l=s;	
 } 
 //�����
void delete_left() 
{
	if(l==r)
	{
		printf("��\n");
		return;
	}
	node* s=l;
	l=l->next;
	l->pre=NULL;
	printf("%d����\n",s->data);
	free(s);
	s=NULL;
 } 
 //�����
void insert_right(int k)
{
	node* s=(node*)malloc(sizeof(node));
    r->data=k;
    s->next=r->next;
    r->next=s;
    s->pre=r;
    r=s;
    
		
 } 
  //�ҳ���
void delete_right() 
{
	if(l==r)
	{
		printf("��\n");
		return;
	}
	node* s=r;
	r=r->pre;
	r->next=NULL;
	printf("%d����\n",r->data);
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

