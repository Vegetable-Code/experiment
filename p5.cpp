#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define N 100

// 图书信息
struct type{
	char loginNum[N]; // 登录号
	char bookName[N]; // 书名  
	char editor[N]; // 作者名 
	char ISBN[N]; // 分类号 
	char publish[N]; // 出版单位 
	char date[N]; // 出版时间
	float price; // 价格  
	struct type *next;	
}Book;

typedef struct type * BooksManage;

BooksManage p,s;

// 系统菜单
void menu() {
	system("cls");
	printf("\n***********欢迎来到***********\n");
	printf("\n\t1.图书录入功能\n");
	printf("\n\t2.图书浏览及保存功能\n");
	printf("\n\t3.图书查询功能\n");
	printf("\n*********图书管理系统*********\n");
}

// 口令验证
void check() {
	char name[6], pass[6]; // 待输入的账号和密码 
	char anum[6] = "admin", bnum[6] = "admin"; // 管理员账号和密码 
	printf("\n********图书管理系统********\n");
	printf("\n\t账号：");
	scanf("%s", &name);
	printf("\n\t密码：");
	scanf("%s", &pass);
	// 验证口令：简略 
	for(int i = 0; i < 6; i++) {
		if(name[i] == anum[i] && pass[i] == bnum[i]) {
			
		} else {
			printf("\n    密码错误!"); 
			Sleep(3000); // 延迟效果 
			system("cls"); // 清屏 
			check(); // 自调 
		}
	}
	menu();
} 

void input(BooksManage *head) {
	int i;
	BooksManage p, s;
	system("cls");
	if(*head == NULL) {
        *head = (BooksManage)calloc(1,sizeof(Book)); // calloc在动态分配完内存后，自动初始化该内存空间为零
        p = *head;
    } else {                            
        p = *head;
        while(p->next) 
        p = p->next; 
    }
    printf("\n***********图书录入***********\n");
    printf("\t请问添加几本书："); 
    scanf("%d",&i);
    while(i)
    {
    	s = (BooksManage)calloc(1,sizeof(Book));
    	printf("\t请输入登录号：");
		scanf("%s",s->loginNum);
		printf("\t请输入书名：");
		scanf("%s",s->bookName);
		printf("\t请输入作者：");
		scanf("%s",s->editor);
		printf("\t请输入分类号：");
		scanf("%s",&s->ISBN);
		printf("\t请输入出版单位：");
		scanf("%s",s->publish);
		printf("\t请输入出版时间：");
		scanf("%s",s->date);
		printf("\t请输入价格：");
		scanf("%f",&s->price);
		i--;
		p->next = s;    /*保存输进去的这个结点*/
		p = p->next;    /*切换到下一个结点*/ 
		p->next = NULL; /*最后一个结点为NULL*/
	}     
	printf("**************************\n"); 
	// 保存延迟效果 
	printf("\t正在保存图书信息");
	Sleep(1000);
	printf("."); 
	Sleep(1000);
	printf("."); 
	Sleep(1000);
	printf(".\n"); 
	Sleep(1000);
    printf("\t图书添加成功!!!\n");
	system("\tpause");
	menu();
}

int save(BooksManage head) {
	FILE *fp;
	fp = fopen("F:/BooksDatabase.txt","w+");
	p = head->next;
	while(p->next != NULL){
		fprintf(fp,"%s\t",p->loginNum);
		fprintf(fp,"%s\t",p->bookName);         
		fprintf(fp,"%s\t",p->editor);          
		fprintf(fp,"%s\t",p->ISBN);
		fprintf(fp,"%s\t",p->publish);
		fprintf(fp,"%s\t",p->date);
		fprintf(fp,"%f\t",p->price);
	    p=p->next;                
	}
	if(p->next == NULL){
		fprintf(fp,"%s\t",p->loginNum);
		fprintf(fp,"%s\t",p->bookName);         
		fprintf(fp,"%s\t",p->editor);          
		fprintf(fp,"%s\t",p->ISBN);
		fprintf(fp,"%s\t",p->publish);
		fprintf(fp,"%s\t",p->date);
		fprintf(fp,"%f\t",p->price);
	}	
	fclose(fp);
	return 1;
}

int main() {
	int num;
	BooksManage head = NULL;
	check();
	while(printf("\n请按照您的需要输入相应的数字：") && scanf("%d", &num) != EOF) {
		switch(num) {
			case 1: 
				input(&head);
				break;
			case 2:
				save(head);
				break;
			case 3:
				printf("图书查询功能");
				break;
			default:
				printf("无此功能，请确认后重新输入");
				system("pause");
				menu();
				break;
		}	
	}
}
