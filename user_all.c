#include<stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
// 전역 변수 설정
FILE* user;

int main(void) {
	// 변수 설정
	int member_menu;		// member_menu: 회원 기능 선택 변수
	char name[20];			// name: 회원 이름 
	char phonenumber[30];	// phonenumber: 회원 전화번호
	int point = 0;			// point 회원의 현재 포인트


	printf("-------------------------------------------\n");
	printf("\t고객님 안녕하세요.\n");
	printf("\t회원 정보 화면입니다.\n");
	printf("-------------------------------------------\n");
	printf("이용하고자 하는 서비스의 번호를 입력해주세요.\n");
	printf("\n1. 회원 가입\t2. 회원 정보 확인\n");
	scanf("%d", &member_menu);
	printf("-------------------------------------------\n");

	// 회원 가입
	if (member_menu == 1) {
		printf("\t고객님 안녕하세요.\n");
		printf("\t회원 가입 화면입니다.\n");
		printf("-------------------------------------------\n");
		user = fopen("user_info.txt", "a");
		if (user == NULL) {
			printf("파일 열기 실패\n");
		}
		while (1) {
			int info_num;
			printf("고객님의 정보를 입력해주세요(양식: 홍길동 01012345678): ");
			scanf("%s %s", &name, &phonenumber);
			printf("------------------로딩중-------------------\n");
			printf("고객님께서 입력하신 정보입니다.\n");
			printf("이름: %s  전화번호:  %s\n", name, phonenumber);
			printf("맞으면 1, 틀리면 2를 입력해주세요\n");
			printf("★★1과 2가 아닌 번호를 입력하게 되면 정보를 다시 입력해야 합니다★★\n");
			printf("입력:");
			scanf("%d", &info_num);
			if (info_num == 1) {
				break;
			}
			else
				continue;
		}
		printf("-------------------로딩중------------------\n");
		fprintf(user, "%s %s    %d\n", name, phonenumber, point);
		fclose(user);
		printf("-------------------------------------------\n");
		printf("%s님 회원가입이 완료됐습니다.\n", name);
		printf("많은 이용 바랍니다. 감사합니다.\n");
		printf("-------------------------------------------\n");

	}
}