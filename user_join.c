#include<stdio.h>
#include <string.h>
#include <memory.h>


int main(void) {
	// ���� ����
	int member_menu;
	FILE* user;
	char name[20];
	char phonenumber[30];
	int point = 0;


	printf("-------------------------------------------\n");
	printf("\t������ �ȳ��ϼ���.\n");
	printf("\tȸ�� ���� ȭ���Դϴ�.\n");
	printf("-------------------------------------------\n");
	printf("�̿��ϰ��� �ϴ� ������ ��ȣ�� �Է����ּ���.\n");
	printf("\n1. ȸ�� ����\t2. ȸ�� ���� Ȯ��\n");
	scanf("%d", &member_menu);
	printf("-------------------------------------------\n");
	if (member_menu == 1) {			// ȸ�� ���� 
		printf("\t������ �ȳ��ϼ���.\n");
		printf("\tȸ�� ���� ȭ���Դϴ�.\n");
		printf("-------------------------------------------\n");
		user = fopen("user_info.txt", "a");
		if (user == NULL) {
			printf("���� ���� ����\n");
		}
		while (1) {
			int info_num;
			printf("�������� ������ �Է����ּ���(���: ȫ�浿 01012345678): ");
			scanf("%s %s", &name, &phonenumber);
			printf("------------------�ε���-------------------\n");
			printf("�����Բ��� �Է��Ͻ� �����Դϴ�.\n");
			printf("�̸�: %s  ��ȭ��ȣ:  %s\n", name, phonenumber);
			printf("������ 1, Ʋ���� 2�� �Է����ּ���\n");
			printf("�ڡ�1�� 2�� �ƴ� ��ȣ�� �Է��ϰ� �Ǹ� ������ �ٽ� �Է��ؾ��մϴ١ڡ�\n");
			printf("�Է�:");
			scanf("%d", &info_num);
			if (info_num == 1) {
				break;
			}
			else
				continue;
		}
		printf("-------------------�ε���------------------\n");
		fprintf(user, "%s %s    %d\n", name, phonenumber, point);
		fclose(user);
		printf("-------------------------------------------\n");
		printf("%s�� ȸ�������� �Ϸ�ƽ��ϴ�.\n", name);
		printf("���� �̿� �ٶ��ϴ�. �����մϴ�.\n");
		printf("-------------------------------------------\n");

	}
}