#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

///˳��ջ///
/*typedef struct{
	int date[maxsize];//ջ��Ԫ�� 
	int top;// ջ��ָ�� 	
}sstack;*/ 

typedef struct{
	int *date;//ջ��Ԫ�� 
	int top;// ջ��ָ�� 	
}sstack;

//--------------------------------------------------------------------- 
//ջ��������ʼ�����пգ���ջ��push),��ջ��pop),��ȡջ��Ԫ�أ�top��
//��˳��ջΪ���� 
//��ʼ�� 
sstack initstack()
{
	sstack s;
	s.date =(int*)malloc(sizeof(int)*maxsize);
	s.top=-1;//��ʼ��ջ��ָ��
	//Ҳ�� s.top=0
	// =-1,�ȼӺ�ֵ��ָ��ָ��ջ��Ԫ��
	//=0���ȸ�ֵ�ټӣ�ָ��ָ�� ջ��Ԫ�ص���һ���洢��Ԫ 
	return s;
 } 
 
//��ջ--��ջ�������޸ģ�ָ�봫�� 
void Pushh(sstack *s,int k)
{
	//ջ�ռ�̶�������һ��Ԫ��Ҫ���ж��Ƿ����ˣ����ܲ��ܼ��� 
	if(s->top==maxsize-1)
	{
		printf("ջ��\n");//ջ���������ܼ��� 
	}
	else{
		s->top++;
		s->date [s->top]=k;
		//s.date [++s.top]=k;
	} 
 }//��top��ʼ��Ϊ0����θ�д 
  
//��ջ
void Popp(sstack *s)
{
	//ɾ��֮ǰ�пգ�����û�е�ɾ
	if(s->top==-1)
	{
		printf("ջ��\n");//ջ�ձ�������ɾ�� 
	 } 
	 else{
	 	s->top--;
	 } 
}//��top��ʼ��Ϊ0����θ�д
 
//��ȡջ��Ԫ��
void gettop(sstack s)
{
	int x;
	//�пգ�����û�еĶ�ȡ 
	if(s.top==-1)
	{
		printf("ջ��\n");//ջ�ձ�������ɾ�� 
	
	 } 
	 else{
	 	x=s.date[s.top]; 
	 	printf("%d\n",x);
	 } 
	
 } //��top��ʼ��Ϊ0����θ�д
int main()
{
	int x;
	sstack s=initstack();
	Pushh(&s,1);
	Pushh(&s,2);
	Pushh(&s,3);
	gettop(s);

	Popp(&s);
	gettop(s);

	Popp(&s);
	gettop(s);
	Pushh(&s,4);
	gettop(s);
	return 0; 

 } 
  
  
  
  
  
  
  
   
