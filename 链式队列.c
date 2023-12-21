#include<stdio.h>
#include<stdlib.h>

///链式队列//
typedef struct qnode{//链式队列结点 
	int data;//队列元素
	struct qnode *next;//指向下一个结点的指针 
}qnode,*lqueue; 

typedef struct linkqueue{//链式队列---可选，不写结构体，直接定义对头队尾指针也可 
	lqueue front,rear;//队头队尾指针,队首指针是链表头结点 
}linkqueue;

//初始化
void initqueue(linkqueue *q)
{   
	q->front=q->rear=(lqueue)malloc(sizeof(qnode));
    if(q->front==NULL)
    {
    	printf("分配失败\n");
	}
	else{
		q->front->next=NULL;
	}
 } 

//入队 
void enqueue(linkqueue* q,int x)
{
	lqueue s=(lqueue )malloc(sizeof(qnode));
	s->data =x;
	s->next =NULL;//新节点插入到链尾
	q->rear->next=s;
	q->rear =s; 
 } 
 //出队，队首指针是链表头结点 ，删除的是队首指针的下一个，即front->next 
void dequeue(linkqueue* q) 
{
	int x;//保存出队元素 
	//先判空，不空才能出 
	if(q->front->next==NULL)
	{
		printf("空\n");//队空，报错 
	 } 
	else{
		lqueue p=q->front->next; 
		x=p->data;
		q->front ->next=p->next ;
		printf("%d\n",x);
		//若原队列只有一个结点了，则删除边空，需要处理尾指针 
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
