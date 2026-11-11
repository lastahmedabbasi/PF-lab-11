#include <stdio.h>

struct Item {
    int id;
    char name[64];
    int quantity;
    float unitPrice;
};

int main() {

    struct Item warehouse[5];
    struct Item *ptr = warehouse;
    
    float totalInventoryValue = 0.0;
    int searchId;
    int found = 0;

    printf("=== Warehouse Inventory Management (Static Array with ->) ===\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter details for Item %d:\n", i + 1);
        
        printf("  Enter Item ID: ");
        scanf("%d", &(ptr + i)->id);
        
        printf("  Enter Item Name: ");
        scanf(" %[^\n]s", (ptr + i)->name);
        
        printf("  Enter Quantity: ");
        scanf("%d", &((ptr + i)->quantity));
        
        printf("  Enter Unit Price: ");
        scanf("%f", &((ptr + i)->unitPrice));
        
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        totalInventoryValue += ((ptr + i)->quantity * (ptr + i)->unitPrice);
    }

    printf("---------------------------------------------\n");
    printf("Total Inventory Value of the Warehouse: $%.2f\n", totalInventoryValue);
    printf("---------------------------------------------\n\n");

    printf("Enter Item ID to search for: ");
    scanf("%d", &searchId);

    for (int i = 0; i < 5; i++) {
        if ((ptr + i)->id == searchId) {
            printf("\nItem Found!\n");
            printf("---------------------------------------------\n");
            printf("ID         : %d\n", (ptr + i)->id);
            printf("Name       : %s\n", (ptr + i)->name);
            printf("Quantity   : %d\n", (ptr + i)->quantity);
            printf("Unit Price : $%.2f\n", (ptr + i)->unitPrice);
            printf("Total Value: $%.2f\n", (ptr + i)->quantity * (ptr + i)->unitPrice);
            printf("---------------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nError: Item with ID %d not found in the warehouse records.\n", searchId);
    }

    return 0;
}
