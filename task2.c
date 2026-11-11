#include <stdio.h>

typedef struct Product {

        int ID;
        int availableStockQuantity;
        float price;
        char name[64];
        char catagory[64];

    } Prod;

void displayProductDetails(Prod prod, float discount) {
    float finalPrice = prod.price * (1-discount);
    printf("====== Product Details =====\n");
    printf("Product: %s\nCatagory: %s\nAvailable Stock: %d\nPrice: %.2f\nPrice after discount: %.2f",
    prod.name, prod.catagory, prod.availableStockQuantity, prod.price, finalPrice);
}

int main(){

    Prod laptop = {
    .ID = 1, 
    .availableStockQuantity = 20, 
    .price = 250549.99, 
    .name = "Laptop", 
    .catagory = "Electronics" 
    };


    float discount = 0.05;
    displayProductDetails(laptop, discount);

    return 0;
}
