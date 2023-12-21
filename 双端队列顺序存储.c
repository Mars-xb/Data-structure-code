#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
//˫�˶��е�˳��洢ʵ�� ����--ѭ������ 
typedef struct {
	int *data;
	int size;//���е�ʵ������
	int l,r; 
} dequeue; 
//��ʼ�� 
dequeue initqueue()
{
	dequeue q;
	q.data =(int*)malloc(sizeof(int)*maxsize);
	if(q.data==NULL)
	{
		printf("����ʧ��\n");
		exit(0);
	}
	q.size=0;
	q.l=q.r=0;
	return q; 
}
/*��һ�����ʱ,0�±�λ�ù̶����ұߵ�һ����ӵ�Ԫ��*/
//�����
void insert_left(dequeue* q,int k)
{
	if(q->size==maxsize)
	{
		printf("��\n"); 
		return ;
	}
	q->l=(q->l-1+maxsize)%maxsize;
	q->data[q->l]=k;
	q->size++;
	
 } 
//��߳���
void delete_left(dequeue* q) 
{
	if(q->size==0)
	{
		printf("��\n");
		return ;
	}
	int x=q->data[q->l];
	printf("%d����\n",x);
	q->l=(q->l+1)%maxsize;
	q->size--;
}
//�� ��� 
void insert_right(dequeue* q,int k)
{
	if(q->size==maxsize)
	{
		printf("��\n"); 
		return ;
	}
	q->data [q->r]=k;
	q->r=(q->r+1)%maxsize; 
	q->size++;
	
 } 
 //�ҳ���
 void delete_right(dequeue* q) 
{
	if(q->size==0)
	{
		printf("��\n");
		return ;
	}
    q->r=(q->r-1+maxsize)%maxsize;
    int x=q->data[q->r];
	printf("%d����\n",x);
	q->size--;
} 
int main()
{
   dequeue q=initqueue();
   //�����+�����
   insert_right(&q,1);
   insert_right(&q,2);
   insert_right(&q,7);
   delete_left(&q);
   delete_left(&q);

    return 0;
   
 	
 }

