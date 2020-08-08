/*×¢£º1¡¢±¾³ÌĞòÊı¾İ½á¹¹ÎªÁ´±í
      2¡¢±¾³ÌĞò¿ÉÒÔÊ¹ÓÃÁ½¸ö¸ñÊ½»¯ÎÄ¼ş¶ÔÏµÍ³½øĞĞ³õÊ¼»¯
	  3¡¢±¾³ÌĞòÊä³öÎÄ¼ş¸ñÊ½ÓëÊäÈëÎÄ¼ş¸ñÊ½²»¼æÈİ
	  4¡¢±¾³ÌĞò¶ÔÒÑ»¹ÊéµÄ½èÔÄĞÅÏ¢²»ÓèÉ¾³ı
	  5¡¢±¾³ÌĞòÎ´½øĞĞÍ¼ĞÎ»¯½çÃæÉè¼Æ
	  6¡¢±¾³ÌĞòĞèÒªÊÖ¶¯ÊäÈë»¹ÊéÊ±¼ä*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//¶¨ÒåÊé¼®ĞÅÏ¢½á¹¹Ìå 
typedef struct node1
{
	int num;//¶¨ÒåÊéºÅ 
    char name[30];//¶¨ÒåÊéÃû 
	char type[30];//¶¨ÒåÀà±ğ 
	char author[30];//¶¨Òå×÷Õß 
	char press[30];//¶¨Òå³ö°æÉç 
	int total;//¶¨Òå¿â´æ×ÜÁ¿ 
	int lend;//¶¨ÒåÒÑ½è³ö²áÊı 
	struct node1* next;//¶¨ÒåÖ¸ÏòÏÂÒ»½ÚµãµÄÖ¸Õë 
}book;

//¶¨ÒåÈÕÆÚ½á¹¹Ìå 
typedef struct
{
	int y,m,d;//¶¨ÒåÄê¡¢ÔÂ¡¢ÈÕ 
}date;

//¶¨Òå½èÔÄĞÅÏ¢½á¹¹Ìå 
typedef struct node2
{
	int stunum;//¶¨ÒåÑ§ºÅ 
	int booknum;//¶¨ÒåÊéºÅ 
	date letime;//¶¨Òå½èÔÄÊ±¼ä 
	date retime;//¶¨Òå»¹ÊéÊ±¼ä 
	struct node2* next;//¶¨ÒåÖ¸ÏòÏÂÒ»½ÚµãµÄÖ¸Õë 
}stu;

//³õÊ¼»¯Êé¼®ĞÅÏ¢½á¹¹Ìå 
book* initbook()
{
	book *head=(book*)malloc(sizeof(book));
	if(!head)
	{
		printf("³õÊ¼»¯´íÎó");
		exit(0);
	}
	head->next=NULL;
	return head;
}

//³õÊ¼»¯½èÔÄĞÅÏ¢½á¹¹Ìå 
stu* initstu()
{
    stu *head=(stu*)malloc(sizeof(stu));
	if(!head)
	{
		printf("³õÊ¼»¯´íÎó");
		exit(0);
	}
	head->next==NULL;
	return head;
}

//É¾³ıºóÖÃ½Úµãº¯Êı 
void del(book* p)
{
   book *p1,*p2;
   p1=p->next;
   p2=p1->next;
   p->next=p2;
   free(p1);
}

//¶¨ÒåÊÖ¶¯Èë¿âº¯Êı 
void push(book *p)
{
	//¸ù¾İÓÃ»§ĞèÇó·ÖÎªĞÂÔöÍ¼Êé»òÔö²¹Í¼Êé 
	printf("*                1¡¢ĞÂÔöÍ¼Êé                    *\n");
	printf("*                2¡¢Ôö²¹Í¼Êé                    *\n"); 
	int n; 
	scanf("%d",&n);
	if(n==1)//ÅĞ¶ÏÊÇ·ñÎªĞÂÔöÍ¼Êé 
	{
	    book *p1,*p2;
	    p1=p;
	    p2=p1->next;
	    while(p2)
        {
		    p1=p2;
		    p2=p1->next;
	    }//½«Ö¸ÕëÒÆ¶¯ÖÁÁ´±íÄ©Î² 
	    p2=(book*)malloc(sizeof(book));
		p1->next=p2;
		p2->total=1;
		p2->lend=0;
		p2->next=NULL;
		printf("ÇëÊäÈëÊéºÅ\n");
		scanf("%d",&p2->num);
		getchar();//å¸æ”¶è¡Œæœ«æ¢è¡Œç¬¦
		printf("ÇëÊäÈëÀà±ğ\n");
		gets(p2->type);
		printf("ÇëÊäÈëÊéÃû\n");
		gets(p2->name);
		printf("ÇëÊäÈë×÷Õß\n");
		gets(p2->author);
		printf("ÇëÊäÈë³ö°æÉç\n");
		gets(p2->press);
	}
	else//Â¼ÈëĞÅÏ¢ÎªÔö²¹Í¼ÊéµÄÇé¿ö 
	{
		book *p1,*p2;
	    p1=p;
	    p2=p1->next;
		printf("ÇëÊäÈëÊéºÅ\n");
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

//ÊÖ¶¯³ö¿âº¯Êı 
void pop(book *p)
{
	book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈëÊéºÅ\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	p2->total--;
    if(!p2->total)//Èç¹û¿â´æÎª0£¬ÔòÒÆ³ıĞÅÏ¢ 
	   del(p1);
}

//¶¨ÒåÎÄ¼şÈë¿âº¯Êı 
void fpush(book* p)
{
	char filename[40];
	printf("ÇëÊäÈëËùÒªÂ¼ÈëÊé¼®¶ÔÓ¦ÎÄ¼şÂ·¾¶\n");
	gets(filename);//»ñÈ¡ÎÄ¼şÂ·¾¶ 
	FILE* fp=fopen(filename,"r");
    book *p1,*p2;
	p2=p;
	p1=p2->next;
	while(p1)
    {
		p2=p1;
		p1=p2->next;
	}//½«Ö¸ÕëÒÆÖÁÁ´±íÄ©Î² 
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

//¶¨ÒåÎÄ¼ş³ö¿âº¯Êı 
void fpop(book* p)
{
    char filename[40];
	printf("ÇëÊäÈëÖ¸¶¨ÎÄ¼şÂ·¾¶\n");
	gets(filename);//»ñÈ¡ÎÄ¼şÂ·¾¶ 
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

//¶¨ÒåÊéºÅ²éÑ¯º¯Êı 
void num_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈëÊéºÅ\n");
	int num;
	scanf("%d",&num);
	while(num!=p2->num)
    {
		p1=p2;
		p2=p1->next;
	}
	printf("%d %s %s %s %s ×Ü¿â´æÁ¿£º%d ×Ü½èÔÄÊı£º%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
}

//¶¨ÒåÊéÃû²éÑ¯º¯Êı 
void name_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈëÊéÃû\n");
	getchar();
	char name[30];
	gets(name);
	while(p2)
    {
		if(strcmp(name,p2->name)==0)
			printf("%d %s %s %s %s ×Ü¿â´æÁ¿£º%d ×Ü½èÔÄÊı£º%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//¶¨ÒåÀà±ğ²éÑ¯º¯Êı 
void type_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈëÀà±ğ\n");
	getchar();
	char type[30];
	gets(type);
	while(p2)
    {
		if(strcmp(type,p2->type)==0)
			printf("%d %s %s %s %s ×Ü¿â´æÁ¿£º%d ×Ü½èÔÄÊı£º%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//¶¨Òå×÷Õß²éÑ¯º¯Êı 
void author_search(book* p)
{
    book *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈë×÷Õß\n");
	getchar();
	char author[30];
	gets(author);
	while(p2)
    {
		if(strcmp(author,p2->author)==0)
			printf("%d %s %s %s %s ×Ü¿â´æÁ¿£º%d ×Ü½èÔÄÊı£º%d\n",p2->num,p2->type,p2->name,p2->author,p2->press,p2->total,p2->lend);
		p1=p2;
		p2=p1->next;
	}
}

//¶¨ÒåÊé¼®²éÑ¯º¯Êı 
void book_search(book* p)
{
    printf("1¡¢¸ù¾İÊéºÅ²éÑ¯\n2¡¢¸ù¾İÊéÃû²éÑ¯\n3¡¢¸ù¾İÀà±ğ²éÑ¯\n4¡¢¸ù¾İ×÷Õß²éÑ¯n");
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

//¶¨ÒåÎÄ¼şÂ¼Èë½èÔÄĞÅÏ¢º¯Êı 
void fstu_push(stu* p)
{
	char filename[40];
	printf("ÇëÊäÈëËùÒªÂ¼Èë½èÔÄĞÅÏ¢¶ÔÓ¦ÎÄ¼şÂ·¾¶:\n");
	gets(filename);//»ñÈ¡ÎÄ¼şÂ·¾¶ 
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

//¶¨Òå²éÑ¯½èÔÄĞÅÏ¢º¯Êı 
void stu_search(stu* p)
{
    stu *p1,*p2;
	p1=p;
	p2=p1->next;
	printf("ÇëÊäÈëÑ§ºÅ\n");
	int num;
	scanf("%d",&num);
	while(p2)
    {
		if(num==p2->stunum)
		{
			printf("Ñ§ºÅ£º%d ÊéºÅ£º%d\n½èÔÄÈÕÆÚ£º%d/%d/%d\nÓ¦»¹ÈÕÆÚ£º%d/%d/%d\n",p2->stunum,p2->booknum,
	        p2->letime.y,p2->letime.m,p2->letime.d,p2->retime.y,p2->retime.m,p2->retime.d);
		}
		p1=p2;
		p2=p1->next;
	}
}

//¶¨Òå½èÊéº¯Êı 
void borrow(book* p1,stu* p2)
{
	int num1,num2;
	printf("ÇëÊäÈëÊéºÅ\n");
    scanf("%d",&num1);
	printf("ÇëÊäÈëÑ§ºÅ\n");
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
	printf("ÇëÊäÈëµ±Ç°ÈÕÆÚ\n");
	scanf("%d %d %d",&p6->letime.y,&p6->letime.m,&p6->letime.d);
	printf("ÇëÊäÈëÓ¦»¹ÈÕÆÚ\n");
	scanf("%d %d %d",&p6->retime.y,&p6->retime.m,&p6->retime.d);
}

//¶¨Òå¼ÆËãÈÕÆÚ²îº¯Êı
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

//¶¨Òåº¯Êıº¯Êı 
void rebook(stu* p2)
{
	int num1,num2;
	printf("ÇëÊäÈëÊéºÅ\n");
    scanf("%d",&num1);
	printf("ÇëÊäÈëÑ§ºÅ\n");
	scanf("%d",&num2);
	stu *p5,*p6;
	p5=p2;
	p6=p5->next;
	while(p6->booknum!=num1||p6->stunum!=num2)
	{
		p5=p6;
		p6=p5->next;
	}
	printf("ÇëÊäÈëµ±Ç°ÈÕÆÚ\n");
	int y,m,d;
	scanf("%d %d %d",&y,&m,&d);
	float cha=diff(p6->retime.y,p6->retime.m,p6->retime.d,y,m,d);
    if(cha>0)
	    printf("Ó¦¸¶·£¿î£º%f\n",cha*0.2);
}

int main()
{
	book* shu=initbook();
    stu* jie=initstu();
    printf("******************»¶Ó­½øÈëÍ¼Êé¹ÜÀíÏµÍ³****************\n");
	printf("********************ÇëÏÈÊäÈëÄúµÄÉí·İ****************\n********************1¡¢¹ÜÀíÔ±****************\n********************2¡¢¶ÁÕß  ****************\n");
	int m,n;
	scanf("%d",&n);
	getchar();//ÓÃÓÚÎüÊÕ»Ø³µ·û 
	int flag=0;
	printf("*********Çë¹ÜÀíÔ±ÏÈ³õÊ¼»¯ÏµÍ³***********\n");
	fpush(shu);
	fstu_push(jie);//³õÊ¼»¯ÏµÍ³ 
	while(1)
	{
		if(flag)
		    break;
		switch(n)
		{
            case 1:
			    printf("*                1¡¢ÊÖ¶¯Èë¿â                     *\n");
				printf("*                2¡¢ÊÖ¶¯³ö¿â                     *\n");
				printf("*           3¡¢ÅúÁ¿Èë¿â£¨¶ÁÈ¡ÎÄ¼ş£©               *\n");
				printf("*         4¡¢´òÓ¡¿â´æÃ÷Ï¸£¨Êä³öÎÄ¼ş£©              *\n");
				printf("*                5¡¢ÍË³öÏµÍ³                      *\n");
				scanf("%d",&m);
				getchar();//å¸æ”¶è¡Œæœ«æ¢è¡Œç¬¦
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
			    printf("*                1¡¢²éÑ¯Êé¼®                      *\n");
				printf("*              2¡¢²éÑ¯½èÔÄĞÅÏ¢                    *\n");
				printf("*                3¡¢½èÔÄÊé¼®                      *\n");
				printf("*                4¡¢¹é»¹Êé¼®                      *\n");
				printf("*                5¡¢ÍË³öÏµÍ³                      *\n");
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
