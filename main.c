#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
#ifdef DEBUG	
	printf("=> DEBUG MODE\n");
	char name[20];
	printf("Enter your name: ");
	scanf("%s", name);
	printf("%s is in debug mode.\n", name);
#endif

	struct Fruit slist[100];
	//int result = 0;
	int count = 0, menu;
	int idx = 0;

	count = loadData(slist);
	idx = count;

	while (1){
	menu = selectMenu();
	if (menu == 0) break;
	if (menu == 1 || menu == 3 || menu == 4){
	    if(count == 0) {
		continue;
	    }
	}
	if(menu == 1 ) {
	    if(count > 0) {
		listProduct(slist, idx);
	    }
	} else if (menu == 2) {
	    count += createProduct(&slist[idx++]);
	    printf("=> 추가됨\n");
	} else if (menu == 3) {
	    int no = selectDataNo(slist, idx);
	    if(no == 0) {
		printf("취소됨!\n");
		continue;
	    }
	    updateProduct(&slist[no-1]);
	} else if (menu == 4) {
	    int no = selectDataNo(slist, idx);
	    if(no == 0) {
		printf("취소됨!\n");
		continue;
	    }
	    int deletok;
	    printf("정말로 삭제하시겠습니까?(삭제 :1)");
	    scanf("%d", &deletok);
	    if(deletok == 1){
		deleteProduct(&slist[no-1]);
		count--;
		printf("=> 삭제됨!\n");
	    }
	} else if (menu == 5) {
	  saveData(slist, idx);
	} else if (menu == 6) {
	  searchName(slist, idx);
	} else if (menu == 7) {
	  searchPrice(slist, idx);
	} else if (menu == 8) {
	  searchDelivery(slist, idx);
	} 
	}
	printf("종료됨!\n");
	return 0;
	}

