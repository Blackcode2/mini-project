struct Fruit {
    char name[20];
    char disc[20];
    char weight[20];
    int price;
    int delivery;
};

int createProduct(struct Fruit *s);

void readProduct(struct Fruit s);

int updateProduct(struct Fruit *s);

int deleteProduct(struct Fruit *s);
