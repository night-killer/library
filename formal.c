/*注：1、本程序数据结构为链表
      2、本程序可以使用两个格式化文件对系统进行初始化
	  3、本程序输出文件格式与输入文件格式不兼容
	  4、本程序对已还书的借阅信息不予删除
	  5、本程序未进行图形化界面设计
	  6、本程序需要手动输入还书时间*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义书籍信息结构体 
typedef struct node1
{
	int num;//定义书号 
    char name[30];//定义书名 
	char type[30];//定义类别 
	char author[30];//定义作者 
	char press[30];//定义出版社 
	int total;//定义库存总量 
	int lend;//定义已借出册数 
	struct node1* next;//定义指向下一节点的指针 
}book;

//定义日期结构体 
typedef struct
{
	int y,m,d;//定义年、月、日 
}date;

//定义借阅信息结构体 
typedef struct node2
{
	int stunum;//定义学号 
	int booknum;//定义书号 
	date letime;//定义借阅时间 
	date retime;//定义还书时间 
	struct node2* next;//定义指向下一节点的指针 
}stu;

//初始化书籍信息结构体 
book* initbook()
{
	book *head=(book*)malloc(sizeof(book));
	if(!head)
	{
		printf("初始化错误");
		exit(0);
	}
	head->next=NULL;
	return head;
}

//初始化借阅信息结构体 
stu* initstu()
{
    stu *head=(stu*)malloc(sizeof(stu));
	if(!head)
	{
		printf("初始化错误");
		exit(0);
	}
	head->next==NULL;
	return head;
}

//删除后置节点函数 
void del(book* p)
{
   book *p1,*p2;
   p1=p->next;
   p2=p1->next;
   p->next=p2;
   free(p1);
}

//定义手动入库函数 
void push(book *p)
{
	//根据用户需求分为新增图书或增补图书 
	printf("*                1、新增图书                    *\n");
	printf("*                2、增补图书                    *\n"); 
	int n; 
	scanf("%d",&n);
	if(n==1)//判断是否为新增图书 
	{
	    book *p1,*p2;
	    p1=p;
	    p2=p1->next;
	    while(p2)
        {
		    p1=p2;
		    p2=p1->next;
	    }//将指针移动至链表末尾 
	    p2=(book*)malloc(sizeof(book));
		p1->next=p2;
		p2->total=1;
		p2->lend=0;
		p2->next=NULL;
		printf("请输入书号\n");
		scanf("%d",&p2->num);
		getchar();//鍚告敹琛屾湯鎹㈣绗�
		printf("请输入类别\n");
		gets(p2->type);
		printf("请输入书名\n");
		gets(p2->name);
		printf("请输入作者\n");
		gets(p2->author);
		printf("请输入出版社\n");
		gets(p2->press);
	}
	else//录入信息为增补图书的情况 
	{
		book *p1,*p2;
	    p1=p;
	    p2=p1->next;
		printf("请输入书号\n");
		int num;
		scanf("%d",&num);
	    while(num!=p1->num)
        {
		    p1=p2;
		    p2=p1->next;
	    }
		p1->total++;
	}
}

//手动出库函数 
void pop(book *p)
{
	book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入书号\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	p2->total--;
    if(!p2->total)//如果库存为0，则移除信息 
	   del(p1);
}

//定义文件入库函数 
void fpush(book* p)
{
	char filename[40];
	printf("请输入所要录入书籍对应文件路径\n");
	gets(filename);//获取文件路径 
	FILE* fp=fopen(filename,"r");
    book *p1,*p2;
	p2=p;
	p1=p2->next;
	while(p1)
    {
		p2=p1;
		p1=p2->next;
	}//将指针移至链表末尾 
	p1=(book*)malloc(sizeof(book));
    p2->next=p1;
	while(fscanf(fp,"%d",&p1->num)!=EOF)
	{   
		fgetc(fp);
		fscanf(fp,"%s",p1->type);
		fgetc(fp);
		fscanf(fp,"%s",p1->name);
		fgetc(fp);
        fscanf(fp,"%s",p1->author);
		fgetc(fp);
		fscanf(fp,"%s",p1->press);
		fscanf(fp,"%d",&p1->total);
		p1->lend=0;
		p2=p1;
		p1=(book*)malloc(sizeof(book));
        p2->next=p1;
	}
	p2->next=NULL;
	free(p1);
	fclose(fp);
}

//定义文件出库函数 
void fpop(book* p)
{
    char filename[40];
	printf("请输入指定文件路径\n");
	gets(filename);//获取文件路径 
	FILE* fp=fopen(filename,"w");
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	while(p2)
	{
	    fprintf(fp,"%d %s %s %s %s %d %d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
        p1=p2;
		p2=p1->next;
	}
	fclose(fp);
}

//定义书号查询函数 
void num_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入书号\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	printf("%d %s %s %s %s 总库存量：%d 总借阅数：%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
}

//定义书名查询函数 
void name_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入书名\n");
	getchar();
	char name[30];
	gets(name);
	while(p2)
    {
		if(strcmp(name,p2->name)==0)
			printf("%d %s %s %s %s 总库存量：%d 总借阅数：%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//定义类别查询函数 
void type_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入类别\n");
	getchar();
	char type[30];
	gets(type);
	while(p2)
    {
		if(strcmp(type,p2->type)==0)
			printf("%d %s %s %s %s 总库存量：%d 总借阅数：%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//定义作者查询函数 
void author_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入作者\n");
	getchar();
	char author[30];
	gets(author);
	while(p2)
    {
		if(strcmp(author,p2->author)==0)
			printf("%d %s %s %s %s 总库存量：%d 总借阅数：%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//定义书籍查询函数 
void book_search(book* p)
{
    printf("1、根据书号查询\n2、根据书名查询\n3、根据类别查询\n4、根据作者查询n");
	int select;
	scanf("%d",&select);
	switch(select)
	{
		case 1:num_search(p);break;
		case 2:name_search(p);break;
		case 3:type_search(p);break;
		case 4:author_search(p);break;
		default:printf("error\n");break;
	}
}

//定义文件录入借阅信息函数 
void fstu_push(stu* p)
{
	char filename[40];
	printf("请输入所要录入借阅信息对应文件路径:\n");
	gets(filename);//获取文件路径 
	FILE* fp=fopen(filename,"r");
    stu *p1,*p2;
	p1=p2=p;
	p1=(stu*)malloc(sizeof(stu));
    p2->next=p1;
	while(fscanf(fp,"%d",&p1->stunum)!=EOF)
	{
		fscanf(fp,"%d",&p1->booknum);
		fscanf(fp,"%d",&p1->letime.y);
		fscanf(fp,"%d",&p1->letime.m);
		fscanf(fp,"%d",&p1->letime.d);
		fscanf(fp,"%d",&p1->retime.y);
		fscanf(fp,"%d",&p1->retime.m);
		fscanf(fp,"%d",&p1->retime.d);
		p2=p1;
		p1=(stu*)malloc(sizeof(stu));
        p2->next=p1;
	}
	p2->next=NULL;
	free(p1);
	fclose(fp);
}

//定义查询借阅信息函数 
void stu_search(stu* p)
{
    stu *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("请输入学号\n");
	int num;
	scanf("%d",&num);
	while(p2)
    {
		if(num==p2->stunum)
		{
			printf("学号：%d 书号：%d\n借阅日期：%d/%d/%d\n应还日期：%d/%d/%d\n",p2->stunum,p2->booknum,
	        p2->letime.y,p2->letime.m,p2->letime.d,p2->retime.y,p2->retime.m,p2->retime.d);
		}
		p1=p2;
		p2=p1->next;
	}
}

//定义借书函数 
void borrow(book* p1,stu* p2)
{
	int num1,num2;
	printf("请输入书号\n");
    scanf("%d",&num1);
	printf("请输入学号\n");
	scanf("%d",&num2);
	book *p3,*p4;
	p3=p1;
	p4=p3->next;
	while(num1!=p4->num)
    {
		p3=p4;
		p4=p3->next;
	}
	p4->lend++;
	stu *p5,*p6;
	p5=p2;
	p6=p5->next;
	while(p6)
	{
		p5=p6;
		p6=p5->next;
	}
	p6=(stu*)malloc(sizeof(stu));
	p5->next=p6;
	p6->next=NULL;
	p6->booknum=num1;
	p6->stunum=num2;
	printf("请输入当前日期\n");
	scanf("%d %d %d",&p6->letime.y,&p6->letime.m,&p6->letime.d);
	printf("请输入应还日期\n");
	scanf("%d %d %d",&p6->retime.y,&p6->retime.m,&p6->retime.d);
}

//定义计算日期差函数
int to_day(int y, int m, int d)
{
  int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int day = 0;
  int i;
  for(i=1; i<y; i++)
  {
      day += (i%4==0 && i%100!=0 || i%400==0)? 366 : 365;
  }
  if(y%4==0 && y%100!=0 || y%400==0) 
      mon[2]++;
  for(i=1; i<m; i++)
  {
      day += mon[i];
  }
  return day + d;
}
int diff(int y1, int m1, int d1, int y2, int m2, int d2)
{
  int a = to_day(y1, m1, d1);
  int b = to_day(y2, m2, d2);
  return b-a;
}

//定义函数函数 
void rebook(stu* p2)
{
	int num1,num2;
	printf("请输入书号\n");
    scanf("%d",&num1);
	printf("请输入学号\n");
	scanf("%d",&num2);
	stu *p5,*p6;
	p5=p2;
	p6=p5->next;
	while(p6->booknum!=num1||p6->stunum!=num2)
	{
		p5=p6;
		p6=p5->next;
	}
	printf("请输入当前日期\n");
	int y,m,d;
	scanf("%d %d %d",&y,&m,&d);
	float cha=diff(p6->retime.y,p6->retime.m,p6->retime.d,y,m,d);
    if(cha>0)
	    printf("应付罚款：%f\n",cha*0.2);
}

int main()
{
	book* shu=initbook();
    stu* jie=initstu();
    printf("******************欢迎进入图书管理系统****************\n");
	printf("********************请先输入您的身份****************\n********************1、管理员****************\n********************2、读者  ****************\n");
	int m,n;
	scanf("%d",&n);
	getchar();//用于吸收回车符 
	int flag=0;
	printf("*********请管理员先初始化系统***********\n");
	fpush(shu);
	fstu_push(jie);//初始化系统 
	while(1)
	{
		if(flag)
		    break;
		switch(n)
		{
            case 1:
			    printf("*                1、手动入库                     *\n");
				printf("*                2、手动出库                     *\n");
				printf("*           3、批量入库（读取文件）               *\n");
				printf("*         4、打印库存明细（输出文件）              *\n");
				printf("*                5、退出系统                      *\n");
				scanf("%d",&m);
				getchar();//鍚告敹琛屾湯鎹㈣绗�
				switch(m)
				{
					case 1:push(shu);break;
					case 2:pop(shu);break;
					case 3:fpush(shu);break;
					case 4:fpop(shu);break;
					case 5:flag=1;
				}
				break;
		    case 2:
			    printf("*                1、查询书籍                      *\n");
				printf("*              2、查询借阅信息                    *\n");
				printf("*                3、借阅书籍                      *\n");
				printf("*                4、归还书籍                      *\n");
				printf("*                5、退出系统                      *\n");
				scanf("%d",&m);
				switch(m)
				{
					case 1:book_search(shu);break;
					case 2:stu_search(jie);break;
					case 3:borrow(shu,jie);break;
					case 4:rebook(jie);break;
					case 5:flag=1;
				}
				break;
		}
	}
	return 0;
}
