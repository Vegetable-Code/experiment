#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100
// ���뺯�� 
int intput(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
}
// �����㷨 
int * sort1(int a[], int len, char style) {
	int i, j, temp;
	// ���� 
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
	// ���� 
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

// ͨ����� 
int output(int a[], int len) {
	printf("��λͬѧ�ĳɼ�Ϊ��");
	for(int j = 0; j < len; j++) {
		printf("%d ", a[j]);
	}
	printf("\n********************-----����ɹ�-----********************\n");
}

int main() {
	// ͨ������ 
	char style = 'a';
	int n;  
	// ����һ 
	int a[10];
	printf("������10��ͬѧ�ĳɼ���");
	intput(a, 10); // ���� 
	int len = sizeof(a) / sizeof(a[0]); // ��ȡ���� 
	sort1(a, len, style);
	output(a, len); //��� 
	// ���ܶ�
	int b[MAX_NUM];
	printf("������������������Ӧ��С��100����");
	scanf("%d", &n);
	printf("������%d��ͬѧ�ĳɼ���", n);
	len = n;
	intput(b, len); //���� 
	sort1(b, len, style);
	output(b, len); // ��� 
} 
