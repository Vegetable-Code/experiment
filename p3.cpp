#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<malloc.h>
#include <windows.h>
#define LEN sizeof(struct Student)
 
// 延迟函数 
void delay() {
	Sleep(1000);
	printf("."); 
	Sleep(1000);
	printf("."); 
	Sleep(1000);
	printf(".\n"); 
	Sleep(1000);
}

// 学生信息 
typedef struct Student{      
	int num;
	float score;
	struct Student *next; 
}LNode, *Linklist;

// 建立链表函数
void CreateList_L(Linklist &L, int n)  { 
    LNode *p;
	int x, i = 0;
	float y;
    L = (Linklist)malloc(sizeof(LNode));
    if(!L) 
		exit(EXIT_FAILURE); 
	L -> next = NULL;
	printf("请输入学生的信息：\n");    
	scanf("%d %f", &x, &y);                 
    while(x != 0 && y != 0 && i < n) {
        p = (LNode *)malloc(sizeof(LNode)); 
        p -> num = x;
		p -> score = y; 
        p -> next = L->next;
        L -> next = p; 
		i++; 
		scanf("%d %f", &x, &y); 
    }
	printf("输入成功！！！\n"); 
} 

// 取值函数
void GetElem_L(Linklist L, int n) { 
    int j = 1;
	LNode *p; 
    p = L -> next; 
    float sum = 0, average = 0;
	float max = p -> score, min = p -> score; 
    while(p != NULL && j <= n) {
		sum += p -> score; 
		if(max < p -> score)
    		max = p -> score;
    	if(min > p -> score) 
			min = p -> score; 
    	p = p -> next;
		++j;
    } 
    average = sum / n;
    printf("数据计算ing");
    delay();
    printf("\n*********学生数据*********\n\n");
	printf("      平均分为：%.1f\n      最高分为：%.1f\n      最低分为：%.1f\n", average, max, min);
	printf("\n*********学生数据*********\n\n"); 
} 

// 删除函数
int ListDelete_L(Linklist &L, int n, int num) { 
    int j, stuNum = 0;
    float score;
	LNode *p, *q; 
	p = L; 
	j = 0;
    while (p->next != NULL && j < n - 1) {
    	stuNum = p -> next -> num;
		if(stuNum == num)
			break; 
        p = p -> next;
		++j;
    }
    if(p -> next == NULL || j > n - 1)
		return -1;
		
    q = p -> next;
	p -> next = q -> next;  
	stuNum = q -> num;
    score = q -> score; 
    printf("删除的学生信息为：%d %.1f\n", stuNum, score);
    printf("删除ing");
	delay(); 
	printf("删除成功！！！\n"); 
	free(q); 
    return 1;
}  

// 插入函数
int ListInsert_L(Linklist &L, int i, int num, float score) { 
    int j;
	LNode *p, *s; 
	p = L; 
	j = 0;
    while (p != NULL && j < i - 1) {
		p = p->next; 
		++j;
	} 
    if(p == NULL || j > i - 1)
		return -1; 
    s = (Linklist)malloc(sizeof(LNode)); 
    s -> num = num;
    s -> score = score;
    s -> next = p->next; 
	p -> next = s; 
    return 1;
}  

// 输出函数
int output(Linklist &L) {
	LNode *p;
	p = L -> next;
	printf("\n***********学生信息***********\n\n"); 
	while(p != NULL) {
        printf("学号为：%d\t成绩为：%.1f",p -> num, p -> score);
        printf("\n");
        p = p -> next;
    }
    printf("\n***********学生信息***********\n\n");
} 

int main(){
    Linklist L;
    int i, n, num;
    float score;
    // 示例部分 
    printf("*******学生信息示例*******\n\n");
    printf("学生信息为：\n"); 
	printf("学号：101\t成绩：100\n\n");
	printf("结尾为：\n");
	printf("学号：0\t\t成绩：0\n\n"); 
	printf("*******学生信息示例*******\n\n");
	// 功能部分
	printf("需要输入几位同学的信息：");
	scanf("%d", &n); 
	CreateList_L(L, n);
	output(L); 
	GetElem_L(L, n);
	printf("\n请输入待删除同学的学号：");
	scanf("%d", &num); 
	ListDelete_L(L, n, num);
	output(L); 
	printf("请输入要插入的位置："); 
	scanf("%d", &i);
	printf("请输入新增同学的信息：");
	scanf("%d %f", &num, &score); 
	ListInsert_L(L, i, num, score);
	output(L);
}
