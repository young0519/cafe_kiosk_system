#include<stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

// 전역 변수 설정
FILE* user;
char user_info[100];    // user_info[100]: 파일에서 찾은 고객님의 정보를 담은 문자열
char name[20];			// name: 회원 이름 
char phonenumber[30];	// phonenumber: 회원 전화번호
int point = 0;			// point 회원의 현재 포인트

// 회원 가입하는 함수
void user_join() {
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

//회원 찾는 함수
void user_search() {
	char user_get[100], user_ans[100];
	int num = 0, pass = 0;
	// user_get: 찾고자 하는 고객님의 전화번호 문자열
	// user_ans: 파일에 적혀있는 고객님의 정보 문자열
	// num: 텍스트파일의 몇번째 행
	// pass: 찾는 문자열이 포함된 행의 갯수

	printf("고객님의 전화번호를 입력하세요(양식: 01012345678)\n");
	printf("입력: ");
	scanf("%s", &user_get);

	user = fopen("user_info.txt", "r");
	if (user == NULL) {
		printf("파일 열기에 실패했습니다.\n");
		printf("회원 가입 후 프로그램을 다시 실행해주세요.\n");
		printf("-------------------------------------------\n");
		return -1;
	}

	// 문자열 탐색하기
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

// 파일에서 찾은 회원 정보 정리 함수
void user_set() {

	if (sscanf(user_info, "%20s %20s    %d", name, phonenumber, &point) != 3) {
		printf("\t등록된 번호가 없습니다.\n");
	}
	else {
		printf("고객님의 회원 정보입니다.\n");
		printf("이름: %s   전화번호: %s    현재 포인트: %d\n", name, phonenumber, point);
	}
}


int main(void) {
	// 변수 설정
	int member_menu;		// member_menu: 회원 기능 선택 변수

	printf("-------------------------------------------\n");
	printf("\t고객님 안녕하세요.\n");
	printf("\t회원 정보 화면입니다.\n");
	printf("-------------------------------------------\n");
	printf("이용하고자 하는 서비스의 번호를 입력해주세요.\n");
	printf("\n1. 회원 가입\t2. 회원 정보 확인\n");
	printf("★★1과 2가 아닌 번호를 입력하게 되면 프로그램이 종료됩니다.★★\n");
	printf("입력: ");
	scanf("%d", &member_menu);
	printf("-------------------------------------------\n");

	while (1) {
		// 회원 가입
		if (member_menu == 1) {
			user_join();
			printf("\t이전 화면으로 돌아갑니다.\n");
			printf("-------------------------------------------\n");
			continue;
		}
		// 회원 정보 찾기
		else if (member_menu == 2) {
			printf("\t고객님 안녕하세요.\n");
			printf("\t회원 정보 확인 화면입니다.\n");
			printf("-------------------------------------------\n");
			user_search();
			printf("-------------------------------------------\n");
			user_set();
			printf("-------------------------------------------\n");
			printf("\t이전 화면으로 돌아갑니다.\n");
			printf("-------------------------------------------\n");
			continue;
		}
		else {
			printf("프로그램을 이용해주셔서 감사합니다.\n");
			printf("-------------------------------------------\n");
			break;
		}
	}

}