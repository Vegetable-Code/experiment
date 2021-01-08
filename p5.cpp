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
 
int main() {
	int num;
	// 系统菜单
	printf("\n*********欢迎来到*********\n");
	printf("\n    1.图书录入功能\n");
	printf("\n    2.图书浏览及保存功能\n");
	printf("\n    3.图书查询功能\n");
	printf("\n********图书管理系统********\n");
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
