#include <stdio.h>
#include "Dijkstra.h"

int main() {
    int map_no, src;

    printf("Enter the graph number to load (e.g., 1, 2, 3): ");
    scanf("%d", &map_no);

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    getgraph(map_no, src);

    return 0;
}
