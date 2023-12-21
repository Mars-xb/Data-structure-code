#include<stdio.h>
#include<stdlib.h>
#define maxsize 10

///顺序栈///
/*typedef struct{
	int date[maxsize];//栈中元素 
	int top;// 栈顶指针 	
}sstack;*/ 

typedef struct{
	int *date;//栈中元素 
	int top;// 栈顶指针 	
}sstack;

//--------------------------------------------------------------------- 
//栈操作：初始化，判空，入栈（push),出栈（pop),读取栈顶元素（top）
//以顺序栈为例子 
//初始化 
sstack initstack()
{
	sstack s;
	s.date =(int*)malloc(sizeof(int)*maxsize);
	s.top=-1;//初始化栈顶指针
	//也有 s.top=0
	// =-1,先加后赋值，指针指向栈顶元素
	//=0，先赋值再加，指针指向 栈顶元素的下一个存储单元 
	return s;
 } 
 
//入栈--对栈进行了修改，指针传递 
void Pushh(sstack *s,int k)
{
	//栈空间固定，加入一个元素要先判断是否满了，还能不能加入 
	if(s->top==maxsize-1)
	{
		printf("栈满\n");//栈满报错，不能加入 
	}
	else{
		s->top++;
		s->date [s->top]=k;
		//s.date [++s.top]=k;
	} 
 }//若top初始化为0，如何改写 
  
//出栈
void Popp(sstack *s)
{
	//删除之前判空，还有没有的删
	if(s->top==-1)
	{
		printf("栈空\n");//栈空报错，不能删除 
	 } 
	 else{
	 	s->top--;
	 } 
}//若top初始化为0，如何改写
 
//读取栈顶元素
void gettop(sstack s)
{
	int x;
	//判空，还有没有的读取 
	if(s.top==-1)
	{
		printf("栈空\n");//栈空报错，不能删除 
	
	 } 
	 else{
	 	x=s.date[s.top]; 
	 	printf("%d\n",x);
	 } 
	
 } //若top初始化为0，如何改写
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
  
  
  
  
  
  
  
   
