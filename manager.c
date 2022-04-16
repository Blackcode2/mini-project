//manager.c
#include <stdio.h>
#include <string.h>
#include "product.h"

// 등록된 전체 제품 출력 함수
void listProduct(struct Fruit *s, int count) {
    printf("\n No   Product      Description      Weight  Price  Delivery \n");
    printf("===============================================================\n");

    for(int i = 0; i < count; i++){
        if(s[i].price == -1) {
            continue;
        }
        printf("%2d ", i+1);
        readProduct(s[i]);
    }
    printf("\n");
}

// 제품을 번호명으로 선택하는 함수
int selectDataNo(struct Fruit *s, int count) {
    int no;
    listProduct(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    getchar();		
    return no;
}

// 리스트 저장 함수
void saveData(struct Fruit *s, int count) {
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i < count; i++){
        if(s[i].price == -1) continue;
       	fprintf(fp, "%s\n", s[i].name);
        fprintf(fp, "%s\n", s[i].disc);
        fprintf(fp, "%s\n", s[i].weight);
        fprintf(fp, "%d\n", s[i].price);
        fprintf(fp, "%d\n", s[i].delivery);
    }

    fclose(fp);
    printf("=> 저장됨! ");
}

 // 저장된 리스트 불러오는 함수
int loadData(struct Fruit *s) {
    int i;

    FILE *fp;

    fp = fopen("product.txt", "rt");
    if(fp != NULL) {
        for(i = 0; i < 100; i++){
		fgets(s[i].name, sizeof(s[i].name), fp);
           	s[i].name[strlen(s[i].name)-1] = '\0';
           	if(feof(fp)) break;
           	fgets(s[i].disc, sizeof(s[i].disc), fp);
            	s[i].disc[strlen(s[i].disc)-1] = '\0';
           	fgets(s[i].weight, sizeof(s[i].weight), fp);
            	s[i].weight[strlen(s[i].weight)-1] = '\0';
            	fscanf(fp, "%d", &s[i].price);
            	fgetc(fp);
            	fscanf(fp, "%d", &s[i].delivery);
            	fgetc(fp);
        }

        fclose(fp);
        printf("=> 로딩 성공!\n");
        return i;
    } else {
        printf("=> 파일없음\n");
        return 0;
    }
}

 // 제품명 검색 함수
void searchName(struct Fruit *s, int count) {
    int scnt = 0;
    char search[20];

    printf("검색할 제품? ");
    scanf("%s", search);

    printf("\n No   Product      Description      Weight  Price  Delivery \n");
    printf("===============================================================\n");

    for(int i = 0; i < count; i++) {
        if(s[i].price == -1) continue;
        if(strstr(s[i].name, search)) {
        printf("%2d", i+1);
        readProduct(s[i]);
        scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

// 제품 가격 검색 함수
void searchPrice(struct Fruit *s, int count) {
    int scnt = 0;
    int search;

    printf("검색할 가격? ");
    scanf("%d", &search);

    printf("\n No   Product      Description      Weight  Price  Delivery \n");
    printf("===============================================================\n");

    for(int i = 0; i < count; i++) {
        if(s[i].price == -1) continue;
        if(s[i].price == search) {
        printf("%2d", i+1);
        readProduct(s[i]);
        scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");

}

// 제품 배송 유형 검색 함수
void searchDelivery(struct Fruit *s, int count) {
    int scnt = 0;
    int search;

    printf("검색할 배송유형 (1: 새벽 배송 2: 택배 배송?)");
    scanf("%d", &search);

    printf("\n No   Product      Description      Weight  Price  Delivery \n");
    printf("===============================================================\n");

    for(int i = 0; i < count; i++) {
        if(s[i].delivery == -1) continue;
        if(s[i].delivery == search) {
        printf("%2d", i+1);
        readProduct(s[i]);
        scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");

}

// 메뉴 선택 함수
int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 제품 검색\n");
    printf("7. 가격 검색\n");
    printf("8. 배송유형 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}
