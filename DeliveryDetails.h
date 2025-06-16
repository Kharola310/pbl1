#ifndef DELIVERY_DETAILS_H
#define DELIVERY_DETAILS_H

void addDeliveryDetail(int map_no, int src, int end, int dist, char **names, char *description);
void displayAllDeliveryDetails();
void displayLastDeliveryDetail();
int getDeliveryCount(); // Added prototype to avoid implicit declaration

#endif
