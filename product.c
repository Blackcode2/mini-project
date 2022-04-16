#include <stdio.h>
#include <string.h>

struct Fruit{
    char name[20];      // 제품명
    char disc[20];      // 제품 설명
    char weight[20];    // 제품 무게
    int price;          // 제품 가격
    int delivery;       // 배송 유형 (1: 새벽배송 / 2: 택배배송)
};

// 제품 추가 함수
int createProduct(struct Fruit *s) {
    printf("제품명: ");
    scanf("%[^\n]s", s->name);
    getchar();

    printf("제품 설명: ");
    scanf("%[^\n]s", s->disc);
    getchar();

    printf("제품 무게: ");
    scanf("%s", s->weight);
    
    printf("제품 가격: ");
    scanf("%d", &s->price);
    
    printf("배송 유형 (1: 새벽 배송 2: 택배 배송?): ");
    scanf("%d", &s->delivery);

    return 1;
}

// 하나의 재품 출력 함수
void readProduct(struct Fruit s) {
    printf("%8s | %20s | %4s | %4d | %5d |\n", s.name, s.disc, s.weight, s.price, s.delivery);
} 


// 제품을 수정해서 업데이트하는 함수
int updateProduct(struct Fruit *s) {
    printf("제품명: ");
    scanf("%[^\n]s", s->name);
    getchar();

    printf("제품 설명: ");
    scanf("%[^\n]s", s->disc);
    getchar();

    printf("제품 무게: ");
    scanf("%s", s->weight);
    
    printf("제품 가격: ");
    scanf("%d", &s->price);
    
    printf("배송 유형 (1: 새벽 배송 2: 택배 배송?): ");
    scanf("%d", &s->delivery);

    printf("=> 수정성공! \n");

    return 1;
}

// 제품을 리스트에서 삭제하는 함수
int deleteProduct(struct Fruit *s) {
    s->price = -1;
    s->delivery = -1;

    return 1;
}
