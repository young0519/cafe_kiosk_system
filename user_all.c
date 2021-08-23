#include<stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

// ���� ���� ����
FILE* user;
char user_info[100];    // user_info[100]: ���Ͽ��� ã�� ������ ������ ���� ���ڿ�
char name[20];			// name: ȸ�� �̸� 
char phonenumber[30];	// phonenumber: ȸ�� ��ȭ��ȣ
int point = 0;			// point ȸ���� ���� ����Ʈ

// ȸ�� �����ϴ� �Լ�
void user_join() {
	printf("\t���� �ȳ��ϼ���.\n");
	printf("\tȸ�� ���� ȭ���Դϴ�.\n");
	printf("-------------------------------------------\n");
	user = fopen("user_info.txt", "a");
	if (user == NULL) {
		printf("���� ���� ����\n");
	}
	while (1) {
		int info_num;
		printf("������ ������ �Է����ּ���(���: ȫ�浿 01012345678): ");
		scanf("%s %s", &name, &phonenumber);
		printf("------------------�ε���-------------------\n");
		printf("���Բ��� �Է��Ͻ� �����Դϴ�.\n");
		printf("�̸�: %s  ��ȭ��ȣ:  %s\n", name, phonenumber);
		printf("������ 1, Ʋ���� 2�� �Է����ּ���\n");
		printf("�ڡ�1�� 2�� �ƴ� ��ȣ�� �Է��ϰ� �Ǹ� ������ �ٽ� �Է��ؾ� �մϴ١ڡ�\n");
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

//ȸ�� ã�� �Լ�
void user_search() {
	char user_get[100], user_ans[100];
	int num = 0, pass = 0;
	// user_get: ã���� �ϴ� ������ ��ȭ��ȣ ���ڿ�
	// user_ans: ���Ͽ� �����ִ� ������ ���� ���ڿ�
	// num: �ؽ�Ʈ������ ���° ��
	// pass: ã�� ���ڿ��� ���Ե� ���� ����

	printf("������ ��ȭ��ȣ�� �Է��ϼ���(���: 01012345678)\n");
	printf("�Է�: ");
	scanf("%s", &user_get);

	user = fopen("user_info.txt", "r");
	if (user == NULL) {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		printf("ȸ�� ���� �� ���α׷��� �ٽ� �������ּ���.\n");
		printf("-------------------------------------------\n");
		return -1;
	}

	// ���ڿ� Ž���ϱ�
	while (!feof(user)) {
		num++;
		fgets(user_ans, 100, user);

		if (strstr(user_ans, user_get) != NULL) {
			strcpy(user_info, user_ans);
			pass++;
		}
	}
	if (pass == 0) {
	}

	fclose(user);
	return 0;
}

// ���Ͽ��� ã�� ȸ�� ���� ���� �Լ�
void user_set() {

	if (sscanf(user_info, "%20s %20s    %d", name, phonenumber, &point) != 3) {
		printf("\t��ϵ� ��ȣ�� �����ϴ�.\n");
	}
	else {
		printf("������ ȸ�� �����Դϴ�.\n");
		printf("�̸�: %s   ��ȭ��ȣ: %s    ���� ����Ʈ: %d\n", name, phonenumber, point);
	}
}


int main(void) {
	// ���� ����
	int member_menu;		// member_menu: ȸ�� ��� ���� ����

	printf("-------------------------------------------\n");
	printf("\t���� �ȳ��ϼ���.\n");
	printf("\tȸ�� ���� ȭ���Դϴ�.\n");
	printf("-------------------------------------------\n");
	printf("�̿��ϰ��� �ϴ� ������ ��ȣ�� �Է����ּ���.\n");
	printf("\n1. ȸ�� ����\t2. ȸ�� ���� Ȯ��\n");
	printf("�ڡ�1�� 2�� �ƴ� ��ȣ�� �Է��ϰ� �Ǹ� ���α׷��� ����˴ϴ�.�ڡ�\n");
	printf("�Է�: ");
	scanf("%d", &member_menu);
	printf("-------------------------------------------\n");

	while (1) {
		// ȸ�� ����
		if (member_menu == 1) {
			user_join();
			printf("\t���� ȭ������ ���ư��ϴ�.\n");
			printf("-------------------------------------------\n");
			continue;
		}
		// ȸ�� ���� ã��
		else if (member_menu == 2) {
			printf("\t���� �ȳ��ϼ���.\n");
			printf("\tȸ�� ���� Ȯ�� ȭ���Դϴ�.\n");
			printf("-------------------------------------------\n");
			user_search();
			printf("-------------------------------------------\n");
			user_set();
			printf("-------------------------------------------\n");
			printf("\t���� ȭ������ ���ư��ϴ�.\n");
			printf("-------------------------------------------\n");
			continue;
		}
		else {
			printf("���α׷��� �̿����ּż� �����մϴ�.\n");
			printf("-------------------------------------------\n");
			break;
		}
	}

}