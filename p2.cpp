#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100
// 输入函数 
int intput(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
}
// 排序算法 
int * sort1(int a[], int len, char style) {
	int i, j, temp;
	// 升序 
	if(style == 'a') {
		for(j = 0; j < len - 1; j++) {
			for(i = 0; i < len - 1; i++) {
				if(a[i] < a[i + 1]) {
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}	
	}
	// 降序 
	if(style == 'd') {
		for(j = 0; j < len - 1; j++) {
			for(i = 0; i < len - 1; i++) {
				if(a[i] > a[i + 1]) {
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
	} 
} 

// 通用输出 
int output(int a[], int len) {
	printf("几位同学的成绩为：");
	for(int j = 0; j < len; j++) {
		printf("%d ", a[j]);
	}
	printf("\n********************-----输出成功-----********************\n");
}

int main() {
	// 通用数据 
	char style = 'a';
	int n;  
	// 功能一 
	int a[10];
	printf("请输入10名同学的成绩：");
	intput(a, 10); // 输入 
	int len = sizeof(a) / sizeof(a[0]); // 获取长度 
	sort1(a, len, style);
	output(a, len); //输出 
	// 功能二
	int b[MAX_NUM];
	printf("请输入总人数（人数应当小于100）：");
	scanf("%d", &n);
	printf("请输入%d名同学的成绩：", n);
	len = n;
	intput(b, len); //输入 
	sort1(b, len, style);
	output(b, len); // 输出 
} 
