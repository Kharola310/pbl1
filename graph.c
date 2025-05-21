#include<stdio.h>
#include"Dijkstra.h"
#include<string.h>
#include<stdlib.h>
#define MAX_LINE 100

void getgraph(int map_no, int src){
  FILE *file = fopen("graph.txt","r");
   if (file == NULL) {
        printf("Could not open file.\n");
        exit(2);
    }

  char line[MAX_LINE];
  int size = 0, found = 0;

  while(fgets(line, sizeof(line),file))
  {
      if(strncmp(line,"# Graph", 7)==0){
       int gnum;
       sscanf(line,"# Graph %d",&gnum);
       if(gnum == map_no){
        found = 1;
        break;
        }
      }
  }
  if(!found){
    printf("graph not found \n");
    exit(1);
  }
  fscanf(file,"%d",&size);
  int graph[size][size];
  for(int i = 0;i < size; i ++){
    for(int j = 0; j < size; j++){
        fscanf(file,"%d",&graph[i][j]);
    }
  }
  fclose(file);
  DijkstrasAlgo(size,graph,src);
}



