#include<stdio.h>
#include<stdlib.h>

///��ʽ����//
typedef struct qnode{//��ʽ���н�� 
	int data;//����Ԫ��
	struct qnode *next;//ָ����һ������ָ�� 
}qnode,*lqueue; 

typedef struct linkqueue{//��ʽ����---��ѡ����д�ṹ�壬ֱ�Ӷ����ͷ��βָ��Ҳ�� 
	lqueue front,rear;//��ͷ��βָ��,����ָ��������ͷ��� 
}linkqueue;

//��ʼ��
void initqueue(linkqueue *q)
{   
	q->front=q->rear=(lqueue)malloc(sizeof(qnode));
    if(q->front==NULL)
    {
    	printf("����ʧ��\n");
	}
	else{
		q->front->next=NULL;
	}
 } 

//��� 
void enqueue(linkqueue* q,int x)
{
	lqueue s=(lqueue )malloc(sizeof(qnode));
	s->data =x;
	s->next =NULL;//�½ڵ���뵽��β
	q->rear->next=s;
	q->rear =s; 
 } 
 //���ӣ�����ָ��������ͷ��� ��ɾ�����Ƕ���ָ�����һ������front->next 
void dequeue(linkqueue* q) 
{
	int x;//�������Ԫ�� 
	//���пգ����ղ��ܳ� 
	if(q->front->next==NULL)
	{
		printf("��\n");//�ӿգ����� 
	 } 
	else{
		lqueue p=q->front->next; 
		x=p->data;
		q->front ->next=p->next ;
		printf("%d\n",x);
		//��ԭ����ֻ��һ������ˣ���ɾ���߿գ���Ҫ����βָ�� 
		if(q->rear =p)
		q->rear =q->front;
		free(p); 
	}
}
int main()
{
	linkqueue* q;
	q=(linkqueue*)malloc(sizeof(linkqueue));
	initqueue(q);
	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	enqueue(q,4);
    dequeue(q);
	dequeue(q);
	return 0;
 } 
