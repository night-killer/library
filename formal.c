/*ע��1�����������ݽṹΪ����
      2�����������ʹ��������ʽ���ļ���ϵͳ���г�ʼ��
	  3������������ļ���ʽ�������ļ���ʽ������
	  4����������ѻ���Ľ�����Ϣ����ɾ��
	  5��������δ����ͼ�λ��������
	  6����������Ҫ�ֶ����뻹��ʱ��*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����鼮��Ϣ�ṹ�� 
typedef struct node1
{
	int num;//������� 
    char name[30];//�������� 
	char type[30];//������� 
	char author[30];//�������� 
	char press[30];//��������� 
	int total;//���������� 
	int lend;//�����ѽ������ 
	struct node1* next;//����ָ����һ�ڵ��ָ�� 
}book;

//�������ڽṹ�� 
typedef struct
{
	int y,m,d;//�����ꡢ�¡��� 
}date;

//���������Ϣ�ṹ�� 
typedef struct node2
{
	int stunum;//����ѧ�� 
	int booknum;//������� 
	date letime;//�������ʱ�� 
	date retime;//���廹��ʱ�� 
	struct node2* next;//����ָ����һ�ڵ��ָ�� 
}stu;

//��ʼ���鼮��Ϣ�ṹ�� 
book* initbook()
{
	book *head=(book*)malloc(sizeof(book));
	if(!head)
	{
		printf("��ʼ������");
		exit(0);
	}
	head->next=NULL;
	return head;
}

//��ʼ��������Ϣ�ṹ�� 
stu* initstu()
{
    stu *head=(stu*)malloc(sizeof(stu));
	if(!head)
	{
		printf("��ʼ������");
		exit(0);
	}
	head->next==NULL;
	return head;
}

//ɾ�����ýڵ㺯�� 
void del(book* p)
{
   book *p1,*p2;
   p1=p->next;
   p2=p1->next;
   p->next=p2;
   free(p1);
}

//�����ֶ���⺯�� 
void push(book *p)
{
	//�����û������Ϊ����ͼ�������ͼ�� 
	printf("*                1������ͼ��                    *\n");
	printf("*                2������ͼ��                    *\n"); 
	int n; 
	scanf("%d",&n);
	if(n==1)//�ж��Ƿ�Ϊ����ͼ�� 
	{
	    book *p1,*p2;
	    p1=p;
	    p2=p1->next;
	    while(p2)
        {
		    p1=p2;
		    p2=p1->next;
	    }//��ָ���ƶ�������ĩβ 
	    p2=(book*)malloc(sizeof(book));
		p1->next=p2;
		p2->total=1;
		p2->lend=0;
		p2->next=NULL;
		printf("���������\n");
		scanf("%d",&p2->num);
		getchar();//吸收行末换行符
		printf("���������\n");
		gets(p2->type);
		printf("����������\n");
		gets(p2->name);
		printf("����������\n");
		gets(p2->author);
		printf("�����������\n");
		gets(p2->press);
	}
	else//¼����ϢΪ����ͼ������ 
	{
		book *p1,*p2;
	    p1=p;
	    p2=p1->next;
		printf("���������\n");
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

//�ֶ����⺯�� 
void pop(book *p)
{
	book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("���������\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	p2->total--;
    if(!p2->total)//������Ϊ0�����Ƴ���Ϣ 
	   del(p1);
}

//�����ļ���⺯�� 
void fpush(book* p)
{
	char filename[40];
	printf("��������Ҫ¼���鼮��Ӧ�ļ�·��\n");
	gets(filename);//��ȡ�ļ�·�� 
	FILE* fp=fopen(filename,"r");
    book *p1,*p2;
	p2=p;
	p1=p2->next;
	while(p1)
    {
		p2=p1;
		p1=p2->next;
	}//��ָ����������ĩβ 
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

//�����ļ����⺯�� 
void fpop(book* p)
{
    char filename[40];
	printf("������ָ���ļ�·��\n");
	gets(filename);//��ȡ�ļ�·�� 
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

//������Ų�ѯ���� 
void num_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("���������\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	printf("%d %s %s %s %s �ܿ������%d �ܽ�������%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
}

//����������ѯ���� 
void name_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("����������\n");
	getchar();
	char name[30];
	gets(name);
	while(p2)
    {
		if(strcmp(name,p2->name)==0)
			printf("%d %s %s %s %s �ܿ������%d �ܽ�������%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//��������ѯ���� 
void type_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("���������\n");
	getchar();
	char type[30];
	gets(type);
	while(p2)
    {
		if(strcmp(type,p2->type)==0)
			printf("%d %s %s %s %s �ܿ������%d �ܽ�������%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//�������߲�ѯ���� 
void author_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("����������\n");
	getchar();
	char author[30];
	gets(author);
	while(p2)
    {
		if(strcmp(author,p2->author)==0)
			printf("%d %s %s %s %s �ܿ������%d �ܽ�������%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//�����鼮��ѯ���� 
void book_search(book* p)
{
    printf("1��������Ų�ѯ\n2������������ѯ\n3����������ѯ\n4���������߲�ѯn");
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

//�����ļ�¼�������Ϣ���� 
void fstu_push(stu* p)
{
	char filename[40];
	printf("��������Ҫ¼�������Ϣ��Ӧ�ļ�·��:\n");
	gets(filename);//��ȡ�ļ�·�� 
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

//�����ѯ������Ϣ���� 
void stu_search(stu* p)
{
    stu *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("������ѧ��\n");
	int num;
	scanf("%d",&num);
	while(p2)
    {
		if(num==p2->stunum)
		{
			printf("ѧ�ţ�%d ��ţ�%d\n�������ڣ�%d/%d/%d\nӦ�����ڣ�%d/%d/%d\n",p2->stunum,p2->booknum,
	        p2->letime.y,p2->letime.m,p2->letime.d,p2->retime.y,p2->retime.m,p2->retime.d);
		}
		p1=p2;
		p2=p1->next;
	}
}

//������麯�� 
void borrow(book* p1,stu* p2)
{
	int num1,num2;
	printf("���������\n");
    scanf("%d",&num1);
	printf("������ѧ��\n");
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
	printf("�����뵱ǰ����\n");
	scanf("%d %d %d",&p6->letime.y,&p6->letime.m,&p6->letime.d);
	printf("������Ӧ������\n");
	scanf("%d %d %d",&p6->retime.y,&p6->retime.m,&p6->retime.d);
}

//����������ڲ��
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

//���庯������ 
void rebook(stu* p2)
{
	int num1,num2;
	printf("���������\n");
    scanf("%d",&num1);
	printf("������ѧ��\n");
	scanf("%d",&num2);
	stu *p5,*p6;
	p5=p2;
	p6=p5->next;
	while(p6->booknum!=num1||p6->stunum!=num2)
	{
		p5=p6;
		p6=p5->next;
	}
	printf("�����뵱ǰ����\n");
	int y,m,d;
	scanf("%d %d %d",&y,&m,&d);
	float cha=diff(p6->retime.y,p6->retime.m,p6->retime.d,y,m,d);
    if(cha>0)
	    printf("Ӧ�����%f\n",cha*0.2);
}

int main()
{
	book* shu=initbook();
    stu* jie=initstu();
    printf("******************��ӭ����ͼ�����ϵͳ****************\n");
	printf("********************���������������****************\n********************1������Ա****************\n********************2������  ****************\n");
	int m,n;
	scanf("%d",&n);
	getchar();//�������ջس��� 
	int flag=0;
	printf("*********�����Ա�ȳ�ʼ��ϵͳ***********\n");
	fpush(shu);
	fstu_push(jie);//��ʼ��ϵͳ 
	while(1)
	{
		if(flag)
		    break;
		switch(n)
		{
            case 1:
			    printf("*                1���ֶ����                     *\n");
				printf("*                2���ֶ�����                     *\n");
				printf("*           3��������⣨��ȡ�ļ���               *\n");
				printf("*         4����ӡ�����ϸ������ļ���              *\n");
				printf("*                5���˳�ϵͳ                      *\n");
				scanf("%d",&m);
				getchar();//吸收行末换行符
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
			    printf("*                1����ѯ�鼮                      *\n");
				printf("*              2����ѯ������Ϣ                    *\n");
				printf("*                3�������鼮                      *\n");
				printf("*                4���黹�鼮                      *\n");
				printf("*                5���˳�ϵͳ                      *\n");
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
