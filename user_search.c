#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

char user_info[100];    // user_info[100]: 파일에서 찾은 고객님의 정보를 담은 문자열

//회원찾는 함수
void user_search() {
    FILE* user;
    char user_get[100], user_ans[100];
    int num = 0, pass = 0;


    // user_get: 찾고자 하는 고객님의 전화번호 문자열
    // user_ans: 파일에 적혀있는 고객님의 정보 문자열
    // num: 텍스트파일의 몇번째 행
    // pass: 찾는 문자열이 포함된 행의 갯수

    printf("고객님의 전화번호를 입력하세요(양식: 01012345678)\n");
    printf("입력: ");
    gets(user_get);

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
    char name[20];
    char phonenumber[20];
    int point;

    if (sscanf(user_info, "%20s %20s    %d", name, phonenumber, &point) != 3) {
        printf("\t등록된 번호가 없습니다.\n");
    }
    else {
        printf("고객님의 회원 정보입니다.\n");
        printf("이름: %s   전화번호: %s    현재 포인트: %d\n", name, phonenumber, point);
    }
}


int main() {
    printf("\t고객님 안녕하세요.\n");
    printf("\t회원 정보 확인 화면입니다.\n");
    printf("-------------------------------------------\n");
    user_search();
    printf("-------------------------------------------\n");
    user_set();
    printf("-------------------------------------------\n");

}