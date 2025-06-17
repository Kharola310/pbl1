#ifndef DELIVERY_DETAILS_H
#define DELIVERY_DETAILS_H

void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description);
void displayAllDeliveryDetails();
int getDeliveryCount();
void printDivider(); // Added prototype for printDivider

#endif
