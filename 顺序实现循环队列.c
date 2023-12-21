#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
///顺序循环队列/// 
typedef struct{
	int date[maxsize];//队列中数据元素
	int front,rear;//对头队尾指针（以索引下标形式表示指针） 
}sqqueue; 
//实现一个循环队列 
//牺牲一个单元来区分头尾

//初始化
void initqueue(sqqueue *q)
{
	q->rear=q->front =0;//初始首尾指针 
 } 


//入队
void enqueue(sqqueue *q,int x)
{
	//先判满，不满才能装
	if((q->rear +1)%maxsize==q->front )
	{
		printf("队满");//队满，报错 
	 } 
	else
	{
		q->date [q->rear]=x;
		q->rear =(q->rear +1)%maxsize;//队尾指针加1取模 
	 } 	 
 } 
//出队
void dequeue(sqqueue *q)
{
	int x;//保存出队元素 
	//先判空，不空才能出 
	if(q->front ==q->rear)
	{
		printf("队空");//队空，报错 
	 } 
	else
	{
		x=q->date [q->front];
		q->front =(q->front +1)%maxsize;//队首指针加1取模 
		printf("%d\n",x);
	 } 	 
 }  
int main()
{
	sqqueue q;
	
	initqueue(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q,3);
	enqueue(&q,2);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	return 0;
 } 
