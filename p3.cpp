#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define LEN sizeof(struct Student)
 
// 学生信息 
struct Student{      
	int num;
	float score;
	struct Student *next; 
};

int n;

// 建立链表函数
struct Student* create() {
	struct Student *head;
    struct Student *p1, *p2;
    n = 0;
    p1 = p2 = (struct Student*)malloc(LEN);
    printf("输入学生的信息：\n");
    scanf("%d %f", &p1->num, &p1->score);
    head = NULL;
    while (p1->num != 0){
        n = n + 1;
        if (n == 1)
            head = p1;
        else 
            p2->next = p1;
        p2 = p1;
        p1 = (struct Student*)malloc(LEN);
        scanf("%d %f", &p1->num, &p1->score);
    }
    p2->next = NULL;
    return(head);
}

// 输出函数 
void output(struct Student *head){
    struct Student *p;
    printf("\n这 %d 名学生的信息为：\n",n);
    p = head;
    if(head != NULL){
        do{
            printf("学号为%d\t成绩为%.1f\n",p->num,p->score);
            p = p->next;
        }while(p != NULL);
    }
}

// 取值函数
void aver(struct Student *head) {
	float sum = 0, average = 0, max = 0, min = 0;
	int i = 0;
	struct Student *p;
	printf("\n这 %d 名学生的平均分为为：\n",n);
    p = head;
    if(head != NULL) {
    	max = p -> score;
    	min =p -> score;
    	do{
    		sum += p -> score;
    		if(max < p -> score) 
    			max = p -> score;
			if(min > p -> score)
				min = p -> score;
            p = p->next;
            i++;
		}while(p != NULL);
	} 
	average = sum / i;
	printf("平均分为%.1f\t最高分为%.1f\t最低分为%.1f", average, max, min); 
}

int main(){
    struct Student *pt;
    // 示例部分 
    printf("*******学生信息示例*******\n\n");
    printf("学生信息为：\n"); 
	printf("学号：101\t成绩：100\n\n");
	printf("结尾为：\n");
	printf("学号：0\t成绩：0\n\n"); 
	printf("*******学生信息示例*******\n\n");
	// 功能部分
    pt = create();
    output(pt);
    aver(pt);
    return 0;
}
