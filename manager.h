//manager.h

// 저장된 제품 리스트로 보여주는 함수
void listProduct(struct Fruit *s, int count);

// 제품 번호를 통해서 제품 선택하는 함수
int selectDataNo(struct Fruit *s, int count);

// 제품 리스트 저장 함수
void saveData(struct Fruit *s, int count);

// 저장된 데이타 불러오는 함수
int loadData(struct Fruit *s);

// 제픔명으로 검색
void searchName(struct Fruit *s, int count);

// 제품 가격으로 검색
void searchPrice(struct Fruit *s, int count);

// 제품 배달 유형으로 검색
void searchDelivery(struct Fruit *s, int count);

// 메뉴 보여주는 함수
int selectMenu();
