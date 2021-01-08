#include <stdio.h>
#include <stdlib.h>
// 学生信息 
struct Student{
	char stuNum[20];
	char name[20];
	float score[3];
}; 

// 功能一 
struct Student stu[10];

int main() {
	int i, j, k;
	float maxScore = 0, sum[10] = {0}; 
	// 功能二 
	for(i = 0; i < 2; i++) {
		printf("请输入第%d个学生的信息：", i + 1);
		scanf("%s %s", stu[i].stuNum, &stu[i].name);
		for(j = 0; j < 3; j++) {
			scanf("%f",&stu[i].score[j]);
		}
	}
	// 功能三 
	k = 0;
	maxScore = stu[0].score[0];
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 3; j++) {
			if(stu[i].score[j] > maxScore) {
				k = i;
				maxScore = stu[i].score[j];
			}
		}
	}
	printf("\n单门成绩最高为第%d名同学：%s %s %.2f\n", k + 1, stu[k].stuNum, stu[k].name, maxScore);
	// 功能四
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 3; j++) {
	 		sum[i] += stu[i].score[j];
	 	}
	}
	k = 0; 
	for(i = 1; i < 2; i++) {
		if(sum[k] < sum[i]) {
	 		k = i;
	 	}
	}
	printf("\n平均分最高为第%d名同学：%s %s %.2f\n", k + 1, stu[k].stuNum, stu[k].name, sum[k]);
	// 功能五
	FILE *fp;
	fopen(&fp, "baocun.txt", "wb");
	fwrite(stu, sizeof(Student), 2, fp); // 写N条信息全部写入文件
	fclose(fp); 	
}
