#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 100

struct type{
	char ISBN[N];//登录号
	char bookName[N]; //书名 
	char subject[N];//科目 
	char editor[N];//主编 
	float price;//价格 
	char publish[N];//出版社
	char date[N];//出版日期 
	int num;//数量 
	struct type *next;	
}Book;
typedef struct type * BooksManage;

void color(short x);//字体颜色 
int password();//管理员密码
void AdministratorMenu();//管理员菜单 
void VisitorMenu();//游客菜单
void SaveBooksdata(BooksManage head);//将数据保存到文件中
void AddBooks(BooksManage *head);//添加图书信息
void ReadBooksdata(BooksManage *head);//将数据从文件中读取 
void DelBooks_Subject(BooksManage head);//按所属学科删除图书信息
void DelBooks_ISBN(BooksManage head);//按ISBN删除图书信息 
void ModifyBooks(BooksManage head);//修改图书信息
void FindBooks(BooksManage head);//查询图书信息
void PrintBooks(BooksManage head);//显示所有图书信息 
void SumBooks(BooksManage head);//求全部图书价值 
int main()
{
	color(10); printf("\t\t\t\t\t* * * * * * * * * * * * * *\n");
	color(14); printf("\t\t\t\t\t* 题目：图书信息管理系统  *\n");
	color(11); printf("\t\t\t\t\t* 班级：19物联网工程      *\n");
	color(12); printf("\t\t\t\t\t* 组员                    *\n");
	color(11); printf("\t\t\t\t\t* 姓名  学号              *\n");
	color(10); printf("\t\t\t\t\t* 张三   100001           *\n");
	color(11); printf("\t\t\t\t\t* 李四   100002           *\n");
	color(14); printf("\t\t\t\t\t* 王五   100003           *\n");
	color(12); printf("\t\t\t\t\t* 日期 ： 2020.01.15      *\n");
	color(10); printf("\t\t\t\t\t* * * * * * * * * * * * * *\n");
	system("title 图书信息管理系统");
	color(10);
	BooksManage head = NULL;
	ReadBooksdata(&head);
	int choice,z,c;
	printf("\n\n\n");
	printf("\t\t\t※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("\t\t\t\t\t\t欢迎光临图书信息管理系统\n");
	printf("\t\t\t--------------------------------------------------------\n");
	printf("\t\t\t\t\t\t【1】游客\n");
	printf("\t\t\t\t\t\t【2】管理员\n");
	printf("\t\t\t\t\t\t【3】退出系统\n");
	printf("\t\t\t--------------------------------------------------------\n");
	while(printf("\t\t\t\t\t\t请选择身份：")&&scanf("%d",&c)!=EOF)
	{
		if(c==1)
		{
			VisitorMenu();
			while (printf("\t\t\t\t\t\t请输入选择项(1-3):")&&scanf("%d",&choice)!=EOF)
    		{
		    	switch (choice)
    			{
    				case 1:                                                /*查询图书信息*/
				    	FindBooks(head);
			    		break;
					case 2:                                                /*显示所有图书信息*/
    	            	PrintBooks(head);
			    		break; 
					case 3:                                                /*返回登录界面*/
						main();
						break;
					case 4:
						exit(0); 
			    	default:
				    	printf("\t\t\t\t\t输入错误!!!\n");
				    	system("pause");
				    	break;
				}
				VisitorMenu();
			}
		}
		else if(c==2)
		{
			z = password();
			AdministratorMenu();
			while (printf("\t请输入选择项(1-8):") && z == 1 && scanf("%d",&choice) != EOF)
    		{
	    		switch (choice)
    			{
		    		case 1:                                                /*录入图书信息*/
				    	AddBooks(&head);
			    		break;  
		    		case 2:                                                /*删除图书信息*/
			    		int sign;
			    		system("cls");
			    		color(10);printf("\t\t\t* * * * * * * * * * * * * * *\n");
			    		color(11);printf("\t\t\t*---------------------------*\n");
			    		color(12);printf("\t\t\t*  输入选择删除图书的方式   *\n");
			    		color(14);printf("\t\t\t*---------------------------*\n");
			    		color(11);printf("\t\t\t*【 1】按所属学科删除图书   *\n");
			    		color(12);printf("\t\t\t*---------------------------*\n");
			    		color(14);printf("\t\t\t*【 2】按图书登录号删除图书 *\n");
			    		color(11);printf("\t\t\t*---------------------------*\n");
			    		color(10);printf("\t\t\t* * * * * * * * * * * * * * *\n");
			    		scanf("\t\t\t%d",&sign);
			    		if(sign == 1)
			    			DelBooks_Subject(head);
			    		else if(sign == 2)
							DelBooks_ISBN(head);
			    		break;
		    		case 3:                                               
			    		ModifyBooks(head);
			   		 	break;
		    		case 4:                                                
				    	FindBooks(head);
			    		break;
					case 5:                                                
            	    	PrintBooks(head);
		    			break;
		    		case 6:                                                
            	    	SumBooks(head);
		    			break;	
		    		case 7:                                                
						main();
						break; 
					case 8:                                                
				    	SaveBooksdata(head);
						exit(0);
		    		default:
				    	printf("\t输入错误!!!\n");
				    	system("pause");
				    	break;
				}
				AdministratorMenu();
			}
		}
		else if(c==3)
			exit(0);
		else
		{
			printf("\t\t\t输入错误!!!\n\n");
		}
	}
	return 0;
}
 
/**管理员密码*/ 
int password()
{
	int i=0;
	char user[10]="admin";
	char Code[10]="admin";
	char getuser[10];
	char Getskey[10];
 
	while(1)
	{
		printf("\t\t\t请输入账号：");
		scanf("%s",getuser);
		printf("\t\t\t请输入密码：");
		while(1)
		{
			Getskey[i]=getch();       /*getch()函数在头文件conio.h中，函数作用为输入的内容不会在屏幕上显示*/
			if(Getskey[i]=='\r')        /* \b = 退格键（backspace）*/
				break;					/* \r = 回车键（carrige return）*/
			else if(Getskey[i]=='\b')
			{
				if(i==0)
					continue;
				printf("\b");
				printf(" ");
				printf("\b");
				i--;
			}
			else
			{
				printf("*");
				i++;
			}
		}
		Getskey[i]='\0';
		if(strcmp(user, getuser) == 0 && strcmp(Code, Getskey) == 0){
			printf("\n\n\n\t\t\t密码正确，请稍等");
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			printf(".");
			Sleep(300);
			return 1;
		}
			
		else
		{
			printf("\n\n\t\t\t账号不存在或密码输入错误，请重新输入\n");
			i = 0;
		}
	}
}

/**管理员菜单*/ 
void AdministratorMenu()                                                
{
	system("cls");//清屏 
	printf("\n\n\n\n\n");
	printf("\t************************************************************\n");
    printf("\t*                                                          *\n");
    printf("\t*                 欢迎来到图书信息管理系统                 *\n");
    printf("\t*                                                          *\n");
    printf("\t*                                                          *\n");
	printf("\t*                          主菜单                          *\n");
	printf("\t*                                                          *\n");
	printf("\t*                     1.录入图书信息                       *\n");
    printf("\t*                                                          *\n");
	printf("\t*                     2.删除图书信息                       *\n");          
	printf("\t*                                                          *\n");
	printf("\t*                     3.修改图书信息                       *\n");
	printf("\t*                                                          *\n");
	printf("\t*                     4.查询图书信息                       *\n");
	printf("\t*                                                          *\n");
	printf("\t*                     5.显示所有图书信息                   *\n");        
    printf("\t*                                                          *\n");
    printf("\t*                     6.全部图书的总价值                   *\n");
    printf("\t*                                                          *\n");
    printf("\t*                     7.返回登录界面                       *\n");
    printf("\t*                                                          *\n");
	printf("\t*                     8.保存数据并退出系统                 *\n"); 
    printf("\t*                                                          *\n");
    printf("\t************************************************************\n\n");
}


/**游客菜单*/ 
void VisitorMenu()                                                 
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t************************************************************\n");
   	printf("\t*                                                          *\n");
   	printf("\t*                 欢迎来到图书信息管理系统                 *\n");
   	printf("\t*                                                          *\n");
   	printf("\t*                                                          *\n");
	printf("\t*                          主菜单                          *\n");
	printf("\t*                                                          *\n");
	printf("\t*                     1.查询图书信息                       *\n");
	printf("\t*                                                          *\n");
	printf("\t*                     2.显示所有图书信息                   *\n");        
   	printf("\t*                                                          *\n");
   	printf("\t*                     3.返回登录界面                       *\n");
   	printf("\t*                                                          *\n");
	printf("\t*                     4.退出系统                           *\n"); 
   	printf("\t*                                                          *\n");
   	printf("\t************************************************************\n\n");
}

/*将数据保存到文件中*/ 
void SaveBooksdata(BooksManage head)                                    
{
	BooksManage p;
	FILE *fp;
	fp = fopen("BooksDatabase.txt","w");
	p = head->next;
	while(p->next != NULL){
		fprintf(fp,"%s\t",p->ISBN);
		fprintf(fp,"%s\t",p->bookName);         
		fprintf(fp,"%s\t",p->subject);          
		fprintf(fp,"%s\t",p->editor);
		fprintf(fp,"%.2f\t",p->price);
		fprintf(fp,"%s\t",p->publish);
		fprintf(fp,"%s\t",p->date);
		fprintf(fp,"%d\n",p->num);
	    p=p->next;                
	}
	if(p->next == NULL){
		fprintf(fp,"%s\t",p->ISBN);
		fprintf(fp,"%s\t",p->bookName);         
		fprintf(fp,"%s\t",p->subject);          
		fprintf(fp,"%s\t",p->editor);
		fprintf(fp,"%.2f\t",p->price);
		fprintf(fp,"%s\t",p->publish);
		fprintf(fp,"%s\t",p->date);
		fprintf(fp,"%d",p->num);
	}	
	fclose(fp);
	return ;
}


/**将数据从文件中读取*/  
void ReadBooksdata(BooksManage *head)                                   
{
        int n;
    BooksManage s, p;
    FILE *fp;
    
    fp=fopen("BooksDatabase.txt","r");

    if(NULL == fp) { 
        head = NULL; 
        return ;
    } 
     
    *head = (BooksManage)calloc(1, sizeof(Book));
    p = *head; 
     
 	 while (!feof(fp))
	{
        s = (BooksManage)calloc(1, sizeof(Book));
		fscanf(fp,"%s",s->ISBN);	            	/*为下个结点分配内存空间 */
		fscanf(fp,"%s",s->bookName);
		fscanf(fp,"%s",s->subject);
		fscanf(fp,"%s",s->editor);
		fscanf(fp,"%f",&s->price);
		fscanf(fp,"%s",s->publish);
		fscanf(fp,"%s",s->date);
		fscanf(fp,"%d",&s->num);
		p->next=s;   /*保存该结点*/
		p=p->next;   /*切换到下一个结点*/
		p->next=NULL; /*保证最后一个结点为NULL*/
	}
     
    fclose(fp);/*关闭文件 */
    return ; 
}

/**字体颜色*/ 
void color(short x)
{
    if(x>=0 && x<=15)
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/**添加图书信息*/ 
void AddBooks(BooksManage *head)                                   
{
	int i;
	BooksManage p, s;
	system("cls");
	if(*head == NULL) {
        *head = (BooksManage)calloc(1,sizeof(Book));
        p = *head;
    } else {                            
        p = *head;
        while(p->next) 
        p = p->next; 
    }
    printf("\n\n\n");
	printf("\t※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
    printf("\t\t\t请问添加几本书："); 
    scanf("%d",&i);
    printf("\t--------------------------------------------------------\n");
    while(i)
    {
    	s = (BooksManage)calloc(1,sizeof(Book));
    	printf("\t\t\t请输入登录号：");
		scanf("%s",s->ISBN);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入书名：");
		scanf("%s",s->bookName);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入书本的所属学科：");
		scanf("%s",s->subject);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入主编：");
		scanf("%s",s->editor);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入价格：");
		scanf("%f",&s->price);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入出版社：");
		scanf("%s",s->publish);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入出版日期：");
		scanf("%s",s->date);
		printf("\t--------------------------------------------------------\n");
		printf("\t\t\t请输入数量：");
		scanf("%d",&s->num);
		printf("\t--------------------------------------------------------\n");
		printf("\n");
		printf("\t--------------------------------------------------------\n");
		i--;
			
		p->next = s;    /*保存输进去的这个结点*/
		p = p->next;    /*切换到下一个结点*/ 
		p->next = NULL; /*最后一个结点为NULL*/
	}
	        
    printf("\t\t\t图书添加成功!!!\n");
	system("pause");
}

/*按所属学科删除图书信息*/ 
void DelBooks_Subject(BooksManage head)                                     
{
	system("cls");
	int flag=0;
	char name[100],ch[10];
	BooksManage p, t;
	
	/**如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");
        return;
    }
	
	p = head;
	printf("\n\n\n");
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("请输入要删除的学科名字；");
	scanf("%s",&name);
	printf("------------------------------------------------------------------------------------\n");
	printf("ISBN\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");   
	printf("------------------------------------------------------------------------------------\n");                                                                                                                                    
	while(p->next)
	{
		t=p;
		p=p->next;                                               /*转换到下一个结点*/
	    if(strcmp(name,p->subject)==0)
	    {
	    	flag=1;
	        printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
	        break;
		}
	}
	 
	if(flag==1)
	{
		printf("是否删除该本图书信息（y/n）");
		scanf("%s",ch);
		printf("----------------------------------------------------------------------\n");
		if(strcmp(ch,"Y") == 0 || strcmp(ch,"y") == 0)
		{
			t->next = p->next;
			free(p);
			printf("该书已删除！\n");
		}
		else
		    return;
	}
	else if(flag == 0)
	    printf("对不起，没找到这本书！\n");
	
	system("pause");
}

/*按ISBN删除图书信息*/ 
void DelBooks_ISBN(BooksManage head)                                     
{
	system("cls");
	int flag=0;
	char ch[10];
	char ISBN[N];
	BooksManage p, t;
	
	/**如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");
        return;
    }
	
	p = head;
	printf("\n\n\n");
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("请输入要删除图书的登录号；");
	scanf("%s",ISBN);
	printf("------------------------------------------------------------------------------------\n");
	printf("登录\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");   
	printf("------------------------------------------------------------------------------------\n");                                                                                                                                   
	while(p->next)
	{
		t=p;
		p=p->next;                                               /*转换到下一个结点*/
	    if(strcmp(ISBN,p->ISBN)==0)
	    {
	    	flag=1;
	        printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
	        break;
		}
	}
	 
	if(flag==1)
	{
		printf("是否删除该本图书信息（y/n）");
		scanf("%s",ch);
		printf("----------------------------------------------------------------------\n");
		if(strcmp(ch,"Y") == 0 || strcmp(ch,"y") == 0)
		{
			t->next = p->next;
			free(p); 
			printf("该书已删除！\n");
		}
		else
		    return;
	}
	else if(flag == 0)
	    printf("没找到那本书！\n");
	
	system("pause");
}

/*修改图书信息*/ 
void ModifyBooks(BooksManage head)                                     
{
	system("cls");
	int flag=0;
	char name[100],ch[5];
	BooksManage p, t;
	
	/* 如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");
        return ;
    }
	
	p = head;
	
	printf("\n\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("请输入要修改的书名:");
	scanf("%s",name);
	printf("--------------------------------------------------------------------\n");
 
	while(p->next)
	{
		p=p->next;                 /*切换到下一个结点*/
	    if(strcmp(name,p->bookName)==0)
	    {
	    	flag = 1;
	    	t = p;
			printf("ISBN\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");   
			printf("------------------------------------------------------------------------------------\n");
	    	printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
		}
	}
	
	if(flag==1)
	{
		printf("--------------------------------------------------------------------\n");
		printf("\t\t是否修改该本图书信息（y/n）:");
		scanf("%s",ch);
		printf("\t--------------------------------------------------------------------\n");
		if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
		{
			int c;
			printf("\t\t【1】ISBN号\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【2】书名\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【3】所属学科\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【4】主编\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【5】价格\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【6】出版社\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【7】出版日期\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t\t【8】数量\n");
			printf("--------------------------------------------------------------------\n");
			printf("\t请输入你要修改的内容；");
			scanf("%d",&c);
			printf("--------------------------------------------------------------------\n");
			p = t;
			switch(c)
			{
				case 1:
				    printf("\t请输入ISBN号：");
			        scanf("%s",p->ISBN);
			        break;
			    case 2:
			        printf("\t请输入书名：");
			        scanf("%s",p->bookName);
			        break;
			    case 3:
			        printf("\t请输入所属学科：");
			        scanf("%s",p->subject);
			        break;
			    case 4:
			        printf("\t请输入主编：");
			        scanf("%s",p->editor);
			        break;
			    case 5:
			        printf("\t请输入价格：");
			        scanf("%f",&p->price);
			        break;
			    case 6:
			        printf("\t请输入出版社：");
			        scanf("%s",p->publish);
			        break;
			    case 7:
			        printf("\t请输入出版日期：");
			        scanf("%s",p->date);
			        break;
			    case 8:
			        printf("\t请输入数量：");
			        scanf("%d",&p->num);
			        break;
			}
			printf("--------------------------------------------------------------------\n");
		    printf("\t修改成功!!!\n");
		}
	}
	
	else if(flag == 0)
	    printf("对不起，该书库没有该书\n");
	    system("pause");
}

/**显示所有图书信息*/ 
void PrintBooks(BooksManage head)                                               
{
	BooksManage p;
	system("cls");
	
	/**如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");//提示任意键继续 
        return ;
    }
	
    p = head->next;
    printf("\n\n\n");
    printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
    printf("                                  图书列表\n");
    printf("------------------------------------------------------------------------------------\n");
	printf("ISBN\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");   
	printf("------------------------------------------------------------------------------------\n");
    
	do
	{
	    printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
	    p = p->next;                           
	}while(p!=NULL);
	
	system("pause");
}

/**求全部图书价值*/
void SumBooks(BooksManage head){
	float sum = 0;
	system("cls");
	BooksManage p;
	/* 如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("\t\t\t\t没有图书信息！\n");
        return;
    }
        for(p = head;p != NULL; p = p->next){
        	sum += p->price * p->num;
		}
	printf("\n\n\n\n\n\n");	
   printf("\t\t\t***********************************\n");
   color(12);printf("\t\t\t*    全部图书的总价值为：%.2f     *\n",sum);
   color(10);printf("\t\t\t***********************************\n");
	system("pause");
} 

/*查询图书信息*/ 
void FindBooks(BooksManage head)                                     
{
	system("cls");
	int choose,flag = 0;
	BooksManage p;
	char b[100];
	char ISBN[N];
	
	/* 如果表头为空 */
    if(head == NULL || head->next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");
        return ;
    }
    
    do
	{
		system("cls");
		printf("\n\n\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		printf("\t\t1.按书名查找\n");
		printf("----------------------------------------------------------------------\n");
		printf("\t\t2.按ISBN号查找\n");
		printf("----------------------------------------------------------------------\n");
		printf("\t\t返回主菜单(其他数字)\n");
		printf("----------------------------------------------------------------------\n");
		printf("\t\t请输入您的选择：");
		scanf("%d",&choose);
		printf("----------------------------------------------------------------------\n");
		p=head;
		
		if(choose == 1)
		{
			printf("输入所查书名：");
			scanf("%s",b);
			printf("----------------------------------------------------------------------\n\n");
			while(p->next)
			{
				p=p->next;                           /*转换到下一个结点*/
				if(strcmp(b,p->bookName)==0)         /*判断是否找到并输出*/
			    {
				     flag=1;
				     printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
					 printf("ISBN\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");
      			  	 printf("------------------------------------------------------------------------------------\n");
				     printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
			    }
			}
			if(flag==0)
			         printf("不存在该信息\n");
		}
		
		else if(choose==2)
		{
			printf("输入所查登录号：");
			scanf("%s",ISBN);
			printf("----------------------------------------------------------------------\n\n");
			while(p->next)
			{
				p=p->next;                         /*转换到下一个结点*/
				if(strcmp(p->ISBN,ISBN) == 0)         /*判断是否找到并输出*/
				{
					flag=1;
				   printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	                printf("ISBN\t书名\t所属学科\t主编\t价格\t出版单位\t出版时间\t数量\n");
	               printf("------------------------------------------------------------------------------------\n");
				    printf("%s\t%s\t%s\t\t%s\t%.2f\t%s\t\t%s\t%d\n",p->ISBN,p->bookName,p->subject,p->editor,p->price,p->publish,p->date,p->num);
				}
			}
			if(flag == 0)
			        printf("不存在该信息\n");
		}
		else
		    return;
		system("pause");
	}while(1);
}
