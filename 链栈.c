#include<stdio.h>
#include<stdlib.h>
///��ջ--������ʵ��ջ///
typedef struct listackNode{//��ջ��� 
	int date;//��ջ�����Ԫ�� 
	struct listackNode* next;//ָ�� 	
}sstack,*listack;
//�˴���listack����������е� linklist����
//listack==sstack *;
//ʹ�� listack ������ջ�еĽ��ָ�룬����ǿ������������ջ�� 
//ʹ�� sstack* ������ջ�еĽ��ָ�룬����ǿ������������ջ�е�ĳ����� 

 
//��ջ����ջ��ָ�룬���ʵ����ջ��������ʵ���Ƚ����
//ֱ���������ͷ���в����������ͷ�൱��ջ��
//��ջ:ͷ�塣 ��ջ��ɾ����Ԫ��� 

//--------------------------------------------------------------------- 
//ջ��������ʼ�����пգ���ջ��push),��ջ��pop),��ȡջ��Ԫ�أ�top��
//��˳��ջΪ���� 
//��ʼ�� 
listack initstack()
{
	listack s=(listack)malloc(sizeof(sstack));
	s->next=NULL;
	return s;
 } 
 
//��ջ--��ջ�������޸ģ�ָ�봫�� 
void Pushh(listack s,int k)
{
	//������������Զ�̬��������������
	//ͷ�巨�����㣬ʵ����ջ 
	sstack *p=(sstack*)malloc(sizeof(sstack));//p�Ǵ�������½�� 
	p->date =k;
	//ͷ�巨 ����p 
	p->next =s->next;
	s->next =p;  
	
 } 
//��ջ
void Popp(listack s)
{
	//ɾ��֮ǰ�пգ�����û�е�ɾ
	if(s->next==NULL)
	{
		printf("ջ��\n");//ջ�ձ�������ɾ�� 
	 } 
	 else
	 {
	 sstack *p=s->next ;//��pָ���ɾ������Ԫ���
	 
	 s->next =p->next ;
	 free(p); 
	 } 
} 
//��ȡջ��Ԫ��
void gettop(listack s)
{
	int x;
	//�пգ�����û�еĶ�ȡ 
	if(s->next==NULL)
	{
		printf("ջ��\n");//ջ�ձ�������ɾ��	 
	 } 
	 else
	 {
	 	x=s->next->date;
		printf("%d\n",x); 
	 } 
	 
 } 
int main()
{
	int x;
	listack s=initstack();
	Pushh(s,1);
	Pushh(s,2);
	Pushh(s,3);
	gettop(s);
	
	Popp(s);
	gettop(s);
	return 0; 
 } 
  
  
  
  
