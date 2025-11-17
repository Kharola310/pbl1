#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"
#define MAX_DESC 100
void printf_map1();

int main() {
    int map_no, src, end, choice;
    char ch;
    char description[MAX_DESC];



    do {
        system("cls");
        printDivider();
        printf("Smart Delivery Route Planner\n");
        printDivider();
        printf("\n");
        printf("Main Menu\n");
        printf("Maps:\n");
        printf("  1. Clementown\n");
        printf("  2. Paris\n");
        printf("  3. XYZ city\n");
        printf("Delivery Details:\n");
        printf("  4. Show all delivery details\n");
        printf("  5. EXIT\n");
        printf("Enter choice (1-5): ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input! Please enter 1-5.\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 4) {
            displayAllDeliveryDetails();
            while (getchar() != '\n');
            printf("\nContinue? (y/n): ");
            ch = getchar();
            printf("\n");
            continue;
        }

        if(choice ==5){
            break;
        }


        map_no = choice;
        printf("\n");
        printDivider();
        printf("Selected Map: %s\n",
               map_no == 1 ? "Clementown" : map_no == 2 ? "Clock Tower" : "XYZ City");
        printDivider();
        printf("\n");
        if(map_no == 1) printf_map1();
        if(map_no == 2) printf_map2();
        if(map_no == 3) printf_map3();

        printf("Enter delivery description: ");
        while (getchar() != '\n'); // Clear buffer
        fgets(description, MAX_DESC, stdin);
        description[strcspn(description, "\n")] = 0; // Remove newline
        if (description[0] == '\0') {
            printf("Description cannot be empty.\n\n");
            continue;
        }



        printf("Enter starting position: ");
        if (scanf("%d", &src) != 1 || src < 0) {
            printf("Invalid input! Source must be non-negative.\n\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the final position: ");
        if (scanf("%d", &end) != 1 || end < 0) {
            printf("Invalid input! Destination must be non-negative.\n\n");
            while (getchar() != '\n');
            continue;
        }
        
        getgraph(map_no, src, end, description);
        

        while (getchar() != '\n');
        printf("\nContinue? (y/n): ");


        ch = getchar();
        printf("\n");
    } while (ch == 'y' || ch == 'Y');

    printDivider();
    printf("Thank you for using Smart Delivery Route Planner!\n");
    printDivider();
    return 0;
}


