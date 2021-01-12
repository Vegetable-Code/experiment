#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//账号为admin 密码为admin
// 图书信息
struct type {
	char ISBN[100]; // 登录号
	char name[100]; // 书名 	
	char author[100]; // 作者名 
	char classification[100]; // 分类号 
	char publish[100]; // 出版单位 
	char date[100]; // 出版时间
	float price; // 价格  
	struct type *next;	
}Book;

typedef struct type * Books;

// 颜色函数
void color(short x) {
    if(x >= 0 && x <= 15)
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// 数据读取函数
void Read(Books *head) {
    int n;
    Books q, p;
    FILE *fp;
    fp=fopen("Data.txt","r");
    if(NULL == fp) { 
        head = NULL; 
        return ;
    } 
    *head = (Books)calloc(1, sizeof(Book));
    p = *head;
 	while (!feof(fp)) {
        q = (Books)calloc(1, sizeof(Book));
		fscanf(fp, "%s", q -> ISBN); /* 为下个结点分配内存空间 */
		fscanf(fp, "%s", q -> name);
		fscanf(fp, "%s", q -> author);
		fscanf(fp, "%s", q -> classification);
		fscanf(fp, "%s", q -> publish);
		fscanf(fp, "%s", q -> date);
		fscanf(fp, "%f\n",&q -> price);
		p->next=q; /* 保存该结点 */
		p=p->next; /* 切换到下一个结点 */
		p->next=NULL; /* 保证最后一个结点为NULL */
	}
    fclose(fp); /* 关闭文件 */
    return ; 
}

void Save(Books head) {
	Books p;
	FILE *fp;
	fp = fopen("Data.txt","w");
	p = head;
	while(p != NULL){
		fprintf(fp,"%s\t", p -> ISBN);
		fprintf(fp,"%s\t", p -> name);
		fprintf(fp,"%s\t", p -> author);
		fprintf(fp,"%s\t", p -> classification);
		fprintf(fp,"%s\t", p -> publish);
		fprintf(fp,"%s\t", p -> date);
		fprintf(fp,"%.2f\n", p -> price);
	    p = p -> next;
	}
	fclose(fp);
	return;
}

// 口令验证
int password() {
	int i=0;
	char user[20] = "admin";
	char code[20] = "admin";
	char getuser[20];
	char getcode[20];
	while(1) {
		printf("\t\t\t请输入账号：");
		scanf("%s", getuser);
		printf("\t\t\t请输入密码：");
		while(1) {
			getcode[i] = getch();//隐藏输入
			if(getcode[i] == '\r')//退格
			break;
			else if(getcode[i] == '\b') {
				if(i == 0)
				continue;
				printf("\b");
				printf(" ");
				printf("\b");
				i--;	
			} 
			else {
				printf("*");
				i++;
			}
		}
		getcode[i] = '\0';
		if(strcmp(user, getuser) == 0 && strcmp(code, getcode) == 0) {
            printf("\n\n\t\t\t密码正确，请稍等");
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
		else {
			printf("\n\n\t\t\t账号不存在或密码输入错误，请重新输入\n");
			i = 0;
		}
	}
}

// 菜单界面
void menu() {
	system("cls");//清屏
	printf("\n\n");
	color(3); printf("\t************************************************************\n");
    color(3); printf("\t*                                                          *\n");
    color(3); printf("\t*                 欢迎来到图书信息管理系统                 *\n");
    color(3); printf("\t*                                                          *\n");
    color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                          主菜单                          *\n");
	color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     1.录入图书信息                       *\n");
    color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     2.查询图书信息                       *\n");          
	color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     3.删除图书信息                       *\n");
	color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     4.修改图书信息                       *\n");
	color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     5.显示所有图书信息                   *\n");        
    color(3); printf("\t*                                                          *\n");
    color(3); printf("\t*                     6.返回登录界面                       *\n");
    color(3); printf("\t*                                                          *\n");
	color(3); printf("\t*                     7.保存数据并退出系统                 *\n"); 
    color(3); printf("\t*                                                          *\n");
    color(3); printf("\t************************************************************\n\n");
}

void Add(Books *head) {
	int i;
	Books p, q;
	p=*head;
	system("cls");                            
   	if(*head != NULL) {
    	while(p->next) 
        	p = p->next; 
    }
    printf("\n\n");
    printf("\t************************************************************\n");
    printf("\t添加几本书？:");
    scanf("%d",&i);
    printf("\t************************************************************\n");
    while(i) {
		q = (Books)calloc(1,sizeof(Book));
    	printf("\t请输入登录号:");
    	scanf("%s",q->ISBN);
    	printf("\t--------------------------------------------------------\n");
		printf("\t请输入书名:");
		scanf("%s",q->name);
		printf("\t--------------------------------------------------------\n");
		printf("\t请输入作者名:");
		scanf("%s",q->author);
		printf("\t--------------------------------------------------------\n");
		printf("\t请输入分类号:");
		scanf("%s",q->classification);
		printf("\t--------------------------------------------------------\n");
		printf("\t请输入出版单位:");
		scanf("%s",q->publish);
		printf("\t--------------------------------------------------------\n");
		printf("\t请输入出版时间:");
		scanf("%s",q->date);
		printf("\t--------------------------------------------------------\n");
		printf("\t请输入价格:");
		scanf("%f",&q->price);
		printf("\n");
		printf("\t************************************************************\n");
		if(*head==NULL) *head = p = q;
		else {
			p -> next = q;
			p = p->next;
		}
		p -> next = NULL;
    	i--;
	}
	printf("\t书本添加成功!\n");
	printf("\t************************************************************\n");
	q = *head;
	do
	{
	printf("\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n",q->ISBN,q->name,q->author,q->classification,q->publish,q->date,q->price);
	q = q -> next;
	}while(q != NULL);
	system("pause");
}

// 查询函数
int Find(Books head) {
	system("cls");
	int choice ,i = 0;
	Books p;
	char j[100];
	char k[100];
	if(head == NULL || head -> next == NULL) {
		printf("没有记录信息!\n");
		system("pause");
		return 1;
	}
	do {
		system("cls");
		printf("\n\n");
		printf("\t************************************************************\n");
		printf("\t1:按书名查找\n");
		printf("\t************************************************************\n");
		printf("\t2:按作者名名查找\n");
		printf("\t************************************************************\n");
		printf("\t3:返回菜单\n");
		printf("\t请选择:");
		scanf("%d",&choice);
		printf("\t************************************************************\n");
		p = head;
		if(choice == 1)
		{
			printf("\t请输入书名");
			scanf("%s",j);
			printf("\t--------------------------------------------------------\n");
			while(p -> next) {
				p = p -> next;
				if(strcmp(j, p -> name) == 0) {
					i = 1;
					printf("\t\t\tISBN\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格\n");
					printf("\t--------------------------------------------------------\n");
					printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n", p -> ISBN,p -> author, p -> classification, p -> publish, p -> date, &p -> price);
					system("pause");
				}
			}
			if(i == 0) printf("不存在\n");
		}
		else if(choice == 2) {
			printf("\t请输入作者名");
			scanf("%s",j);
			printf("\t--------------------------------------------------------\n");
			while(p -> next) {
				p = p -> next;
				if(strcmp(j, p -> author) == 0)
				{
					i = 1;
					printf("\t\t\tISBN\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格\n");
					printf("\t--------------------------------------------------------\n");
					printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n", p -> ISBN, p -> name, p -> author, p -> classification, p -> publish, p -> date, &p -> price);
					system("pause");
				}
			}
			if(i == 0)
			printf("\t不存在\n");
		}
		else if(choice == 3)
		{
			return 1;
			system("pause");
		}
		else
		{
			printf("\t请输入1-3!:");
			scanf("%d", &choice);
		}
	}while(choice != 1 || choice != 2 || choice != 3);
}

// 删除函数
void Delet(Books head) {
	system("cls");
	int i = 0;
	char k[10], ISBN[100];
	Books p, q;
	if(head == NULL || head -> next == NULL) {
    	printf("没有记录图书信息！\n");
        system("pause");
    }
    p = head;
	printf("\t************************************************************\n");
	printf("\t请输入要删除的书的登录号:");
	scanf("%s", ISBN);
	printf("\t--------------------------------------------------------\n");
	printf("\t\t\tISBN\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格\n");
	printf("\t--------------------------------------------------------\n");
	while(p -> next) {
		q = p;
		p = p -> next;                                               /*转换到下一个结点*/
	    if(strcmp(ISBN, p -> ISBN) == 0) {
	    	i = 1;
	    	printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n", p -> ISBN, p -> name, p -> author, p -> classification, p -> publish, p -> date, &p -> price);
			break;
	    }
	}
	if(i == 1) {
		printf("\t确认删除该本图书信息？（y/n）");
		scanf("%s", k);
		printf("\t----------------------------------------------------------------------\n");
		if(strcmp(k, "Y") == 0 || strcmp(k, "y") == 0) {
			q -> next = p -> next;
			free(p); 
			printf("\t该书已删除！\n");
		}
		else system("pause");
	}
	else if(i == 0)
	    printf("\t没找到那本书！\n");
	system("pause");
}

// 修改函数
void change(Books head) {
	system("cls");
	int i = 0,j;
	char name[100], k[10];
	Books p, q;
	/* 如果表头为空 */
    if(head == NULL || head -> next == NULL) {
        printf("没有记录图书信息！\n");
        system("pause");
    }
	p = head;
	printf("\n\n\n");
	printf("\t************************************************************\n");
	printf("\t请输入要修改的书名:");
	scanf("%s", name);
	printf("\t--------------------------------------------------------------------\n");
	while(p -> next) {
		p = p -> next; /*切换到下一个结点*/
	    if(strcmp(name, p -> name) == 0) {
	    	i = 1;
	    	q = p;
			printf("\t\t\tISBN\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格\n");
			printf("\t--------------------------------------------------------\n");
			printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n", p -> ISBN, p -> name, p -> author, p -> classification, p -> publish, p -> date, &p -> price);
		}
	}
	if(i == 1) {
		printf("--------------------------------------------------------------------\n");
		printf("\t是否修改该本图书信息（y/n）:");
		scanf("%s", k);
		printf("\t--------------------------------------------------------------------\n");
		if(strcmp(k, "Y") == 0 || strcmp(k, "y") == 0) {
			int c;
			printf("\t1：登陆号\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t2：书名\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t3：作者名\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t4：分类号\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t5：出版单位\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t6：出版时间\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t7：价格\n");
			printf("\t--------------------------------------------------------------------\n");
			printf("\t请输入你要修改的内容:");
			scanf("%d", &j);
			printf("\t--------------------------------------------------------------------\n");
			p = q;
			switch(j) {
				case 1:
				    printf("\t请输入登陆号：");
			        scanf("%s", p -> ISBN);
			        break;
			    case 2:
			        printf("\t请输入书名：");
			        scanf("%s", p -> name);
			        break;
			    case 3:
			        printf("\t请输入作者名：");
			        scanf("%s", p -> author);
			        break;
			    case 4:
			        printf("\t请输入分类号：");
			        scanf("%s", p -> classification);
			        break;
			    case 5:
			        printf("\t请输入出版单位：");
			        scanf("%s", &p -> publish);
			        break;
			    case 6:
			        printf("\t请输入出版时间：");
			        scanf("%s", p -> date);
			        break;
			    case 7:
			        printf("\t请输入价格：");
			        scanf("%f", &p -> price);
			        break;
			}
			printf("--------------------------------------------------------------------\n");
		    printf("\t修改成功\n");
		    system("pause");
		}
	}
	
	else if(i == 0)
	    printf("\t对不起，该书库没有该书\n");
	system("pause");
}

void show(Books head) {
	Books p;
	system("cls");
	/**如果表头为空 */
    if(head == NULL || head -> next == NULL) {
        printf("\t没有记录图书信息！\n");
        system("pause");
        return ;
    }
	
    p = head -> next;
    printf("\n\n\n");
    printf("\t************************************************************\n");
	printf("\t图书列表\n");
    printf("\t--------------------------------------------------------------------\n");
	printf("\t\t\tISBN\t书名\t作者名\t分类号\t出版单位\t出版时间\t价格\n");
	printf("\t--------------------------------------------------------------------\n");
	do {
	    printf("\t\t\t%s\t%s\t%s\t%s\t%s\t%s\t%.2f\n", p -> ISBN, p -> name, p -> author, p -> classification, p -> publish, p -> date, p -> price);
	    p = p -> next;
	}while(p != NULL);
	
	system("pause");
}

int main() {
	int choice,z;
	printf("\n\n\n");
	color(10); printf("\t\t* * * * * * * * * * * * * *\n");
	color(11); printf("\t\t* 题目：图书信息管理系统  *\n");
	color(9);  printf("\t\t* 班级：19物联网工程      *\n");
	color(15); printf("\t\t* 姓名：罗帆              *\n");
	color(14); printf("\t\t* 学号：20190070126       *\n");
	color(10); printf("\t\t* * * * * * * * * * * * * *\n");
	system("title 图书信息管理系统");
	Books head = NULL;
	Read(&head);
	z = password();
	menu();
	while (printf("\t请输入选择项(1-7):") && z == 1 && scanf("%d", &choice) != EOF) {
	    switch (choice) {
    		case 1:// 录入
					Add(&head);
					break;
			case 2:// 查询
					 Find(head);
					 break;
			case 3:// 删除
			 		Delet(head);
			 		break;
			case 4:// 修改
					change(head);
					break;
			case 5:// 显示所有
					show(head);
					break;
			case 6:// 返回登陆界面
					system("cls");
					main();
					break; 
			case 7:// 保存退出
					Save(head);
					exit(0); 
			default:
					printf("输入错误!");
					system("pause");
					break;
    	}
    	menu();		
   	}
}
