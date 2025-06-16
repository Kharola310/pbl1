#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dijkstra.h"
#include "DeliveryDetails.h"

#define MAX_DESC 100

int main() {
    int map_no, src, end, choice;
    char ch;
    char description[MAX_DESC];

    printf("\n");
    printf("================================================\n");
    printf("   Welcome to Smart Delivery Route Planner\n");
    printf("================================================\n");

    do {
        printf("\n=== Main Menu ===\n");
        printf("MAPS\n");
        printf(" 1. Clementown\n");
        printf(" 2. Clock Tower\n");
        printf(" 3. XYZ City\n");
        printf("DELIVERY DETAILS\n");
        printf(" 4. Show all delivery details\n");
        printf(" 5. Show the last delivery detail\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 4) {
            displayAllDeliveryDetails();
            while (getchar() != '\n');
            continue;
        }

        if (choice == 5) {
            displayLastDeliveryDetail();
            while (getchar() != '\n');
            continue;
        }

        map_no = choice;
        printf("\nSelected Map: %s\n",
               map_no == 1 ? "Clementown" : map_no == 2 ? "Clock Tower" : "XYZ City");

        printf("Enter the source vertex (starting location): ");
        if (scanf("%d", &src) != 1 || src < 0) {
            printf("Invalid input! Source vertex must be a non-negative number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the end vertex (destination location): ");
        if (scanf("%d", &end) != 1 || end < 0) {
            printf("Invalid input! End vertex must be a non-negative number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter delivery description (up to %d characters): ", MAX_DESC - 1);
        while (getchar() != '\n'); // Clear buffer
        fgets(description, MAX_DESC, stdin);
        description[strcspn(description, "\n")] = 0; // Remove newline
        if (description[0] == '\0') {
            printf("Description cannot be empty. Please try again.\n");
            continue;
        }

        getgraph(map_no, src, end, description);

        printf("\nDo you want to continue? (y/n): ");
        while (getchar() != '\n');
        ch = getchar();
    } while (ch == 'y' || ch == 'Y');

    printf("\n================================================\n");
    printf("   Thank you for using Smart Delivery Route Planner!\n");
    printf("================================================\n");
    return 0;
}
