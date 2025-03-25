#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LANDMARKS 100
#define MAX_NAME_LEN 50

// 定义行走路线（边）
typedef struct WalkingLink {
    char from[MAX_NAME_LEN];
    char to[MAX_NAME_LEN];
    int duration; // 行走时间（分钟）
} WalkingLink;

// 定义渡轮班次（边）
typedef struct FerrySchedule {
    char from[MAX_NAME_LEN];
    char to[MAX_NAME_LEN];
    int departure; // 出发时间（HHMM格式，如1130）
    int arrival;   // 到达时间（HHMM格式，如1152）
} FerrySchedule;

// 定义地标（顶点）
typedef struct Landmark {
    char name[MAX_NAME_LEN];
} Landmark;

// 定义整个交通图
typedef struct TransportGraph {
    Landmark landmarks[MAX_LANDMARKS];
    int numLandmarks;
    WalkingLink walkingLinks[MAX_LANDMARKS];
    int numWalkingLinks;
    FerrySchedule ferrySchedules[MAX_LANDMARKS];
    int numFerrySchedule;
} TransportGraph;


void initGraph(TransportGraph *graph);
void addLandmark(TransportGraph *graph, char *name);
void addWalkingLink(TransportGraph *graph, char *from, char *to, char *duration);
void addFerrySchedule(TransportGraph *graph, char *from, char *to, int *depart, int *arrive);
void findDirectPath(TransportGraph *graph, char *from, char *to, int *departTime);
