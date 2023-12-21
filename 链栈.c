#include<stdio.h>
#include<stdlib.h>
///链栈--单链表实现栈///
typedef struct listackNode{//链栈结点 
	int date;//链栈结点中元素 
	struct listackNode* next;//指针 	
}sstack,*listack;
//此处的listack与链表代码中的 linklist类似
//listack==sstack *;
//使用 listack 声明链栈中的结点指针，意在强调操作对象是栈； 
//使用 sstack* 声明链栈中的结点指针，意在强调操作对象是栈中的某个结点 

 
//链栈中无栈顶指针，如何实现在栈顶操作，实现先进后出
//直接在链表表头进行操作，链表表头相当于栈顶
//入栈:头插。 出栈：删除首元结点 

//--------------------------------------------------------------------- 
//栈操作：初始化，判空，入栈（push),出栈（pop),读取栈顶元素（top）
//以顺序栈为例子 
//初始化 
listack initstack()
{
	listack s=(listack)malloc(sizeof(sstack));
	s->next=NULL;
	return s;
 } 
 
//入栈--对栈进行了修改，指针传递 
void Pushh(listack s,int k)
{
	//链表结点个数可以动态调整，无需判满
	//头插法插入结点，实现入栈 
	sstack *p=(sstack*)malloc(sizeof(sstack));//p是待插入的新结点 
	p->date =k;
	//头插法 插入p 
	p->next =s->next;
	s->next =p;  
	
 } 
//出栈
void Popp(listack s)
{
	//删除之前判空，还有没有的删
	if(s->next==NULL)
	{
		printf("栈空\n");//栈空报错，不能删除 
	 } 
	 else
	 {
	 sstack *p=s->next ;//让p指向待删除的首元结点
	 
	 s->next =p->next ;
	 free(p); 
	 } 
} 
//读取栈顶元素
void gettop(listack s)
{
	int x;
	//判空，还有没有的读取 
	if(s->next==NULL)
	{
		printf("栈空\n");//栈空报错，不能删除	 
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
  
  
  
  
