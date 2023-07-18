#ifndef GRAPHS_H
#define GRAPHS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    char* vertex;          // The vertex this edge points to
    struct Edge* next;     // The next edge in the linked list
} Edge;

typedef struct Vertex {
    char* key;             // The key of the vertex
    Edge* edges;           // A linked list of edges
    int edgeCount;         // The number of edges
    int edgeCapacity;      // The current capacity of edges
} Vertex;

typedef struct Graph {
    Vertex* vertices;      // The array of vertices
    int vertexCount;       // The number of vertices
    int vertexCapacity;    // The current capacity of vertices
} Graph;

Graph* createGraph();
void addVertex(Graph* graph, char* key);
void addEdge(Graph* graph, char* key1, char* key2);
void deleteVertex(Graph* graph, char* key);
void deleteEdge(Graph* graph, char* key1, char* key2);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);

#endif
