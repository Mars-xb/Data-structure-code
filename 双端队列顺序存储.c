#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
//双端队列的顺序存储实现 基于--循环数组 
typedef struct {
	int *data;
	int size;//队列的实际容量
	int l,r; 
} dequeue; 
//初始化 
dequeue initqueue()
{
	dequeue q;
	q.data =(int*)malloc(sizeof(int)*maxsize);
	if(q.data==NULL)
	{
		printf("分配失败\n");
		exit(0);
	}
	q.size=0;
	q.l=q.r=0;
	return q; 
}
/*第一次入队时,0下标位置固定放右边第一次入队的元素*/
//左入队
void insert_left(dequeue* q,int k)
{
	if(q->size==maxsize)
	{
		printf("满\n"); 
		return ;
	}
	q->l=(q->l-1+maxsize)%maxsize;
	q->data[q->l]=k;
	q->size++;
	
 } 
//左边出队
void delete_left(dequeue* q) 
{
	if(q->size==0)
	{
		printf("空\n");
		return ;
	}
	int x=q->data[q->l];
	printf("%d出队\n",x);
	q->l=(q->l+1)%maxsize;
	q->size--;
}
//右 入队 
void insert_right(dequeue* q,int k)
{
	if(q->size==maxsize)
	{
		printf("满\n"); 
		return ;
	}
	q->data [q->r]=k;
	q->r=(q->r+1)%maxsize; 
	q->size++;
	
 } 
 //右出队
 void delete_right(dequeue* q) 
{
	if(q->size==0)
	{
		printf("空\n");
		return ;
	}
    q->r=(q->r-1+maxsize)%maxsize;
    int x=q->data[q->r];
	printf("%d出队\n",x);
	q->size--;
} 
int main()
{
   dequeue q=initqueue();
   //右入队+左出队
   insert_right(&q,1);
   insert_right(&q,2);
   insert_right(&q,7);
   delete_left(&q);
   delete_left(&q);

    return 0;
   
 	
 }

