#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project.h"
#include <windows.h>

#define MAX_DETAIL 200

void printDivider() {
    printf("----------------------------------------\n");
}

void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description) {
    FILE *file = fopen("delivery_details.txt", "a");
    if (file == NULL) {
        printf("Could not open delivery details file.\n\n");
        return;
    }

    char *map_names[] = {"Clementown", "Paris", "XYZ City"};
    fprintf(file, "Delivery %d\n", getDeliveryCount() + 1);
    fprintf(file, "  Map: %s\n", map_names[map_no - 1]);
    fprintf(file, "  From: %s\n", names[src]);
    fprintf(file, "  To: %s\n", names[end]);
    fprintf(file, "  Distance: %d\n", dist);
    fprintf(file, "  Description: %s\n", description);
    fprintf(file, "\n");
    fclose(file);
    printf("Delivery details added successfully.\n");
    Sleep(1000);
    printDivider();
    printf("\n");
}

int getDeliveryCount() {
    FILE *file = fopen("delivery_details.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    char line[MAX_DETAIL];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Delivery ", 9) == 0) {
            count++;
        }
    }
    fclose(file);
    return count;
}

void displayAllDeliveryDetails() {
    FILE *file = fopen("delivery_details.txt", "r");
    if (file == NULL) {
        printf("No delivery details available.\n\n");
        return;
    }
    system("cls");
    printDivider();
    printf("All Delivery Details\n");
    printDivider();
    char line[MAX_DETAIL];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    if (getDeliveryCount() == 0) {
        printf("No delivery details found.\n\n");
    }
    fclose(file);
    printf("\n");
}


