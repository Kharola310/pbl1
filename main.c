#include <stdio.h>
#include "Dijkstra.h"

int main() {
    int map_no, src;
    char choice;

    printf("** WELCOME TO SMART DELIVERY ROUTE PLANNER **\n");

    do {

        printf("\nEnter the graph number (1, 2, or 3): ");
        if (scanf("%d", &map_no) != 1 || map_no < 1 || map_no > 3) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");

            while (getchar() != '\n');
            continue;
        }

        // Prompt for source vertex
        printf("Enter the source vertex (starting location): ");
        if (scanf("%d", &src) != 1 || src < 0) {
            printf("Invalid input! Source vertex must be a non-negative number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        // Call getgraph to process the graph (assuming it validates src against graph size)
        getgraph(map_no, src);

        // Ask if user wants to try another graph
        printf("\nDo you want to try another graph? (y/n): ");
        while (getchar() != '\n'); // Clear buffer
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Smart Delivery Route Planner!\n");
    return 0;
}
