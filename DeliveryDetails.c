#include <stdio.h>
#include <string.h>
#include "DeliveryDetails.h"

#define MAX_DETAIL 200

void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description) {
    FILE *file = fopen("delivery_details.txt", "a");
    if (file == NULL) {
        printf("Could not open delivery details file.\n");
        return;
    }

    char *map_names[] = {"Clementown", "Clock Tower", "XYZ City"};
    fprintf(file, "Delivery %d:\n", getDeliveryCount() + 1);
    fprintf(file, "  Map: %s\n", map_names[map_no - 1]);
    fprintf(file, "  From: %s\n", names[src]);
    fprintf(file, "  To: %s\n", names[end]);
    fprintf(file, "  Distance: %d\n", dist);
    fprintf(file, "  Description: %s\n", description);
    fprintf(file, "\n");
    fclose(file);
    printf("Delivery details added successfully.\n");
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
        printf("No delivery details available.\n");
        return;
    }

    printf("\n=== All Delivery Details ===\n");
    char line[MAX_DETAIL];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    if (getDeliveryCount() == 0) {
        printf("No delivery details found.\n");
    }
    fclose(file);
}

void displayLastDeliveryDetail() {
    FILE *file = fopen("delivery_details.txt", "r");
    if (file == NULL) {
        printf("No delivery details available.\n");
        return;
    }

    char line[MAX_DETAIL];
    char last_delivery[MAX_DETAIL * 7] = "";
    int in_last_delivery = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Delivery ", 9) == 0) {
            in_last_delivery = 1;
            strcpy(last_delivery, line);
        } else if (in_last_delivery && line[0] != '\n') {
            strcat(last_delivery, line);
        } else if (line[0] == '\n') {
            in_last_delivery = 0;
        }
    }
    if (strlen(last_delivery) > 0) {
        printf("\n=== Last Delivery Detail ===\n");
        printf("%s", last_delivery);
    } else {
        printf("No delivery details found.\n");
    }
    fclose(file);
}
