#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_NUM 10
#define ALL_cls 3

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
struct Student{
	char stuNum[20];
	char name;
	float score[ALL_cls];
}; 

struct Student stu[MAX_NUM];

// 输入函数
void input() {
	FILE *fp;
	int i; 
	printf("**********学生信息录入**********\n\n"); 
	if((fp = fopen("stud.dat", "wb")) == NULL) {
		printf("cannot open file\n");
	}
	for(i = 0; i < MAX_NUM; i++) {
		printf("\t");
		scanf("%s %c %f %f %f", stu[i].stuNum, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		fwrite(&stu[i], sizeof(struct Student), 1, fp);
		fclose(fp);
	}
	printf("\n\t保存ing");
	delay();
	printf("\n************录入成功************\n"); 
} 

// 单门成绩最高
void single() {
	float maxScore = 0;
	int i, j, k = 0;
	maxScore = stu[0].score[0];
	for(i = 0; i < MAX_NUM; i++) {
		for(j = 0; j < ALL_cls; j++) {
			if(stu[i].score[j] > maxScore) {
				k = i;
				maxScore = stu[i].score[j];
			}
		}
	}
	printf("\n单门成绩最高为第%d名同学：%s %c %.2f\n", k + 1, stu[k].stuNum, stu[k].name, maxScore);
} 

// 平均分最高
void aver() {
	int i, j;
	float sum[MAX_NUM] = {0}, average[MAX_NUM] = {0}, maxAver = 0;
	for(i = 0; i < MAX_NUM; i++) {
		for(j = 0; j < ALL_cls; j++) {
	 		sum[i] += stu[i].score[j];
	 	}
	 	average[i] = sum[i] / ALL_cls;
	}
	maxAver = average[0];
	j = 0;
	for(i = 1; i < MAX_NUM; i++) {
		if(maxAver < average[i]) {
			maxAver = average[i];
			j = i;
		}
	}
	printf("\n平均分最高为第%d名同学：%s %c %.2f\n", j + 1, stu[j].stuNum, stu[j].name, maxAver);
} 

// 读取函数 
void readAll() {
	int i;
	FILE *fp;
	printf("\n**************学生信息**************\n\n");
	printf("学号\t姓名\t成绩一\t成绩二\t成绩三\n"); 
	if((fp = fopen("stud.dat", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for(i = 0; i < MAX_NUM; i++) {
	    fseek(fp, i * sizeof(struct Student), 0);
		fread(&stu[i], sizeof(struct Student), 1, fp);
		printf("%s\t%c\t%.2f\t%.2f\t%.2f\n", stu[i].stuNum, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]);		
	}
	printf("\n**************学生信息**************\n\n");
}

// 交换函数
void swap(char *a, char *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
} 

// 排序保存并读取函数
void sort() {
	int i, j, k;
	float aver[MAX_NUM] = {0};
	for(i = 0; i < MAX_NUM; i++) {
		for(j = 0; j < ALL_cls; j++) {
			aver[i] += stu[i].score[j] / 3;
		}
	}
	FILE *fp;
	if((fp = fopen("stud.dat", "rb")) == NULL) {
		printf("cannot open file\n");
		exit(0);
	}
	for(i = 0; i < MAX_NUM - 1; i++) {
		k = i;
		for(j = i + 1; j < MAX_NUM; j++) {
			if(aver[j] > aver[k])
				k = j; 
		}
		swap(&stu[k].name, &stu[i].name);
	}
	printf("平均分排序为：");
	for(i = 0; i < MAX_NUM; i++) {
		printf("%c ", stu[i].name);
	}
} 

int main() {	
	input();
	single();
	aver();
	readAll();
	sort();
}

/*
0 a 10 20 30
1 b 20 30 40
2 c 25 35 45 
3 d 15 25 35
4 e 45 60 20
5 f 80 60 10
6 g 80 90 60
7 h 50 16 75
8 i 23 56 46
9 j 83 65 40
*/
