#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

char user_info[100];    // user_info[100]: ���Ͽ��� ã�� ������ ������ ���� ���ڿ�

//ȸ��ã�� �Լ�
void user_search() {
    FILE* user;
    char user_get[100], user_ans[100];
    int num = 0, pass = 0;


    // user_get: ã���� �ϴ� ������ ��ȭ��ȣ ���ڿ�
    // user_ans: ���Ͽ� �����ִ� ������ ���� ���ڿ�
    // num: �ؽ�Ʈ������ ���° ��
    // pass: ã�� ���ڿ��� ���Ե� ���� ����

    printf("������ ��ȭ��ȣ�� �Է��ϼ���(���: 01012345678)\n");
    printf("�Է�: ");
    gets(user_get);

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
    char name[20];
    char phonenumber[20];
    int point;

    if (sscanf(user_info, "%20s %20s    %d", name, phonenumber, &point) != 3) {
        printf("\t��ϵ� ��ȣ�� �����ϴ�.\n");
    }
    else {
        printf("������ ȸ�� �����Դϴ�.\n");
        printf("�̸�: %s   ��ȭ��ȣ: %s    ���� ����Ʈ: %d\n", name, phonenumber, point);
    }
}


int main() {
    printf("\t���� �ȳ��ϼ���.\n");
    printf("\tȸ�� ���� Ȯ�� ȭ���Դϴ�.\n");
    printf("-------------------------------------------\n");
    user_search();
    printf("-------------------------------------------\n");
    user_set();
    printf("-------------------------------------------\n");

}