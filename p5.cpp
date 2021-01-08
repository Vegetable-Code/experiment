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

// 系统菜单
void menu() {
	system("cls");
	printf("\n*********欢迎来到*********\n");
	printf("\n    1.图书录入功能\n");
	printf("\n    2.图书浏览及保存功能\n");
	printf("\n    3.图书查询功能\n");
	printf("\n********图书管理系统********\n");
}

// 口令验证
void check() {
	char name[6], pass[6]; // 待输入的账号和密码 
	char anum[6] = "admin", bnum[6] = "admin"; // 管理员账号和密码 
	printf("\n********图书管理系统********\n");
	printf("\n    账号：");
	scanf("%s", &name);
	printf("\n    密码：");
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

int main() {
	int num;
	check();
	printf("\n请按照您的需要输入相应的数字：");
	scanf("%d", &num);
	switch(num) {
		case 1: 
			printf("图书录入功能");
			break;
		case 2:
			printf("图书浏览及保存功能");
			break;
		case 3:
			printf("图书查询功能");
			break;
	}
}
