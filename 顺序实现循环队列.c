#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
///˳��ѭ������/// 
typedef struct{
	int date[maxsize];//����������Ԫ��
	int front,rear;//��ͷ��βָ�루�������±���ʽ��ʾָ�룩 
}sqqueue; 
//ʵ��һ��ѭ������ 
//����һ����Ԫ������ͷβ

//��ʼ��
void initqueue(sqqueue *q)
{
	q->rear=q->front =0;//��ʼ��βָ�� 
 } 


//���
void enqueue(sqqueue *q,int x)
{
	//����������������װ
	if((q->rear +1)%maxsize==q->front )
	{
		printf("����");//���������� 
	 } 
	else
	{
		q->date [q->rear]=x;
		q->rear =(q->rear +1)%maxsize;//��βָ���1ȡģ 
	 } 	 
 } 
//����
void dequeue(sqqueue *q)
{
	int x;//�������Ԫ�� 
	//���пգ����ղ��ܳ� 
	if(q->front ==q->rear)
	{
		printf("�ӿ�");//�ӿգ����� 
	 } 
	else
	{
		x=q->date [q->front];
		q->front =(q->front +1)%maxsize;//����ָ���1ȡģ 
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
